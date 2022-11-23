/*
 *    Copyright (c) <2002-2009> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
 *    including without limitation the rights to use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the Software,
 *    and to permit persons to whom the Software is furnished to do so, 
 *    subject to the following conditions:
 *    
 *    The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef CURLPP_INFO_HPP
#define CURLPP_INFO_HPP



#include "Easy.hpp"


namespace curlpp
{

	/**
	* this struct is type help to check the right type is used CURLINFO_XXXX
	* using `CURLINFO_TYPEMASK` mask
	*
	* rmq : `CURLINFO_SLIST` and CURLINFO_PTR have the same value, so a specialtized
	* struct is need for each CURLINFO_XXX using this type
	*/

	template<CURLINFO info, uint32_t type_mask = (info& CURLINFO_TYPEMASK)>
	struct InfoType;

	template<CURLINFO info>
	struct InfoType<info, CURLINFO_STRING> {
		using Type = char*;
	};

	template<CURLINFO info>
	struct InfoType<info, CURLINFO_LONG> {
		using Type = long;
	};

	template<CURLINFO info>
	struct InfoType<info, CURLINFO_DOUBLE> {
		using Type = double;
	};

	template<CURLINFO info>
	struct InfoType<info, CURLINFO_OFF_T> {
		using Type = curl_off_t;
	};

	template<CURLINFO info>
	struct InfoType<info, CURLINFO_SOCKET> {
		using Type = curl_socket_t;
	};

	template<>
	struct InfoType<CURLINFO_COOKIELIST, CURLINFO_SLIST> {
		using Type = curl_slist*;
	};

	template<>
	struct InfoType<CURLINFO_SSL_ENGINES, CURLINFO_SLIST> {
		using Type = curl_slist*;
	};

	template<>
	struct InfoType<CURLINFO_CERTINFO, CURLINFO_PTR> {
		using Type = curl_certinfo*;
	};

	template<>
	struct InfoType<CURLINFO_TLS_SESSION, CURLINFO_PTR> {
		using Type = curl_tlssessioninfo*;
	};

	template<>
	struct InfoType<CURLINFO_TLS_SSL_PTR, CURLINFO_PTR> {
		using Type = curl_tlssessioninfo*;
	};

	/**
	* This class is responsible of retreiving the Info from
	* a handle. This is the class you use when you want to do
	* so.
	*/

	template<CURLINFO info, typename T = typename InfoType<info>::Type>
	struct Info 
	{
		static void get(const Easy& handle, T & value);
		static T get(const Easy& handle);
	};


	/**
	* This class is used when an info is not available for the
	* current libcURL version.
	*/

	template<CURLINFO info, typename T>
	struct NotAvailableInfo : Info<info, T>
	{
		static void get(const Easy& handle, T& value);
		static T get(const Easy& handle);
	};

	/**
	* This is the only class that is authorized to retrieve
	* info from a curlpp::Easy class. So, this is the class
	* you need to use when you specialize the class
	* curlpp::InfoTypeConverter. This class is in fact used
	* as a proxy, just to be sure that nobody access curlpp::Easy's 
	* private data.
	*/

	struct InfoGetter
	{
		template<typename T>
		static void get(const Easy& handle, CURLINFO info, T& value);
	};
	
	/**
	* This is the class you need to specialize if you use
	* a special type that libcURL is not aware of. This class
	* need to call curlpp::InfoGetter::get function. See 
	* curlpp::InfoGetter for more information.
	*/
	template<CURLINFO info, typename T>
	struct InfoTypeConverter;

	/**
	* InfoTypeConverter specialized to use type deduced from CURLINFO
	*/
	template<CURLINFO info>
	struct InfoTypeConverter<info, typename InfoType<info>::Type>
	{
		using Type = typename InfoType<info>::Type;

		static void get(const Easy& handle, Type& value) {
			InfoGetter::get<Type>(handle, info, value);
		}
	}; 

	/**
	* InfoTypeConverter specialized to convert char* to std::string
	*/
	template<CURLINFO info>
	struct InfoTypeConverter<info, std::string> 
	{
		static void get(const Easy& handle, std::string& value) {
			auto tmp = Info<info, char*>::get(handle);
			value = tmp ? tmp : "";
		}
	};

	/**
	* InfoTypeConverter specialized to convert curl_slist* to std::list<std::string>
	*/
	template<CURLINFO info>
	struct InfoTypeConverter<info, std::list<std::string>> 
	{
		static void get(const Easy& handle, std::list<std::string>& value) {
			auto tmpList = Info<info, curl_slist*>::get(handle);
			value = internal::SList(tmpList).list();
		}
	};

} // namespace curlpp

namespace cURLpp = curlpp;


#include "Info.inl"

#endif // #ifndef CURLPP_INFO_HPP
