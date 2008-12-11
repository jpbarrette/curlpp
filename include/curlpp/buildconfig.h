/*
 *    Copyright (c) <2002-2004> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_BUILDCONFIG_H
#define CURLPP_BUILDCONFIG_H

/*
 * Decorate exportable functions for Win32 DLL linking.
 * This avoids using a .def file for building curlpp.dll.
 */
#if !defined(CURLPP_STATICLIB)
	#if defined(BUILDING_CURLPP)
		#if (defined(WIN32) || defined(_WIN32))
			#define CURLPPAPI  __declspec(dllexport)
		#else
			#define CURLPPAPI
		#endif

		#define CURLPP_LIB_EXPORT
		#undef CURLPP_LIB_IMPORT
	#else
		#if (defined(WIN32) || defined(_WIN32))
			#define CURLPPAPI  __declspec(dllimport)
		#else
			#define CURLPPAPI
		#endif

		#define CURLPP_LIB_IMPORT
		#undef CURLPP_LIB_EXPORT
	#endif
#else
	#define CURLPPAPI

	#undef CURLPP_LIB_IMPORT
	#undef CURLPP_LIB_EXPORT
#endif

#if defined (CURLPP_SELF_CONTAINED)
	#if defined(BUILDING_CURLPP)
		#define CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
		#define CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION
	#else
		#undef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
		#undef CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION
	#endif
#else
	#if defined(BUILDING_CURLPP)
		#define CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
		#undef CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION
	#else
		#define CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
		#undef CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION
	#endif
#endif


#endif // #ifndef CURLPP_BUILDCONFIG_H
