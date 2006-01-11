/*
 *    Copyright (c) <2002-2006> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_TYPES_HPP
#define CURLPP_TYPES_HPP

#include <utilspp/Functors.hpp>

namespace cURLpp
{

  namespace Types
  {
    typedef utilspp::Functor< 
      size_t, 
      TYPE_LIST_3(char*, size_t, size_t) > WriteFunctionFunctor;
    typedef utilspp::Functor< 
      size_t, 
      TYPE_LIST_3(char*, size_t, size_t) > ReadFunctionFunctor;


    // DebugFunctor related typedefs
    typedef utilspp::Functor<
      int,
      TYPE_LIST_3(curl_infotype, 
		  char *, 
		  size_t) > DebugFunctionFunctor;
    
    typedef utilspp::Functor< 
      CURLcode,
      TYPE_LIST_1(void *) > SslCtxFunctionFunctor;
    typedef utilspp::Functor<
      int,
      TYPE_LIST_4(double, double, double, double) > ProgressFunctionFunctor;
  };
};

#endif
