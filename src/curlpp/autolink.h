/*
 *    Copyright (c) <2005> <Giuseppe "Cowo" Corbelli>
 *
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files
 *    (cURLpp), to deal in the Software without restriction,
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

#ifndef __AUTOLINK__H_
#define __AUTOLINK__H_

/*
 * Auto-link feature on win32 supported compilers. Reading boost sources it seems
 * that _MSC_VER definition does not guarantee a ms compiler. However this should
 * not be a problem for autolink.
 */
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

    #if defined(_MSC_VER ) || defined(__INTEL_COMPILER) || defined(__ICL) || \
    defined(__ICC) || defined(__ECC) || defined(__MWERKS__) || defined(__BORLANDC__)

        #if defined(_DEBUG) || defined(DEBUG)
			#pragma comment(lib, "libcurlppd.lib")
		#else //DEBUG
			#pragma comment(lib, "libcurlpp.lib")
		#endif //DEBUG

    #endif //Supported compilers

#endif //Windows

#endif //__AUTOLINK__H_
