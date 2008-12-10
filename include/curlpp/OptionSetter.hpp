/*
 *    Copyright (c) <2002-2008> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_OPTION_SETTER_HPP
#define CURLPP_OPTION_SETTER_HPP

#include "buildconfig.h"

#include "OptionContainerType.hpp"
#include "CurlHandle.hpp"
#include "Types.hpp"

namespace curlpp
{

	/**
	* This class is used to specialize some option settings.
	*/

	template<typename OptionValueType, CURLoption optionType>
	class CURLPPAPI OptionSetter
	{

	public:

		typedef typename OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* This class is used to specialize the std::string options type.
	*/

	template<CURLoption optionType>
	class CURLPPAPI OptionSetter<std::string, optionType>
	{

	public:

		typedef curlpp::OptionContainerType<std::string>::HandleOptionType ParamType;
		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* This class is used to specialize the curlpp::SList options type.
	*/

	template<CURLoption optionType>
	class CURLPPAPI OptionSetter<std::list<std::string>, optionType>
	{

	public:

		typedef std::list<std::string> OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* This class is used to specialize the curlpp::HttpPost options type.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::Forms, CURLOPT_HTTPPOST>
	{

	public:

		typedef curlpp::Forms OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::WriteFunctionFunctor,
		CURLOPT_WRITEFUNCTION>
	{

	public:

		typedef curlpp::types::WriteFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};


#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::BoostWriteFunction, 
		CURLOPT_WRITEFUNCTION>
	{

	public:

		typedef curlpp::types::BoostWriteFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};

#endif // #ifdef HAVE_BOOST


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<FILE *, 
		CURLOPT_WRITEDATA>
	{

	public:

		typedef FILE * OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<std::ostream *, 
		CURLOPT_WRITEDATA>
	{

	public:

		typedef std::ostream * OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::ReadFunctionFunctor, 
		CURLOPT_READFUNCTION>
	{

	public:

		typedef curlpp::types::ReadFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::BoostReadFunction, 
		CURLOPT_READFUNCTION>
	{
	public:
		typedef curlpp::types::BoostReadFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};

#endif // #ifdef HAVE_BOOST


	/**
	* \todo Brief comment.
	*/

	template <>
	class CURLPPAPI OptionSetter<FILE *, 
		CURLOPT_READDATA>
	{

	public:

		typedef FILE * OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<std::istream *, 
		CURLOPT_READDATA>
	{

	public:

		typedef std::istream * OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::ProgressFunctionFunctor, 
		CURLOPT_PROGRESSFUNCTION>
	{

	public:

		typedef curlpp::types::ProgressFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};


#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter<curlpp::types::BoostProgressFunction, 
		CURLOPT_PROGRESSFUNCTION>
	{

	public:

		typedef curlpp::types::BoostProgressFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};

#endif // #ifdef HAVE_BOOST


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::WriteFunctionFunctor, 
		CURLOPT_HEADERFUNCTION >
	
	{

	public:

		typedef curlpp::types::WriteFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};

#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::BoostWriteFunction, 
		CURLOPT_HEADERFUNCTION >
	{
	public:
		typedef curlpp::types::BoostWriteFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};
#endif


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::DebugFunctionFunctor, 
		CURLOPT_DEBUGFUNCTION >
	{
	public:
		typedef curlpp::types::DebugFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};


#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::BoostDebugFunction, 
		CURLOPT_DEBUGFUNCTION >
	{

	public:

		typedef curlpp::types::BoostDebugFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};

#endif // #ifdef HAVE_BOOST


	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::SslCtxFunctionFunctor, 
		CURLOPT_SSL_CTX_FUNCTION >
	{

	public:

		typedef curlpp::types::SslCtxFunctionFunctor OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);

	};

#ifdef HAVE_BOOST

	/**
	* \todo Brief comment.
	*/

	template<>
	class CURLPPAPI OptionSetter< curlpp::types::BoostSslCtxFunction, 
		CURLOPT_SSL_CTX_FUNCTION >
	{

	public:

		typedef curlpp::types::BoostSslCtxFunction OptionValueType;
		typedef curlpp::OptionContainerType<OptionValueType>::HandleOptionType ParamType;

		static void setOpt(curlpp::CurlHandle * handle, ParamType value);
	};

#endif // #ifdef HAVE_BOOST

} // namespace curlpp

#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "OptionSetter.inl"
#endif

namespace cURLpp = curlpp;

#endif // #ifndef CURLPP_OPTION_SETTER_HPP

