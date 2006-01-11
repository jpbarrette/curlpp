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

#ifndef STORAGE_OPTIONS_HPP
#define STORAGE_OPTIONS_HPP

#include "dllfct.h"
#include "Option.hpp"
#include "TypeTrait.hpp"


namespace cURLpp 
{
  namespace Options 
  {
    template< typename CallbackType, 
	      typename DataType, 
	      CURLoption CallbackOptionValue,
	      CURLoption DataOptionValue >
    class CURLPPAPI StorageOption :  public cURLpp::OptionList
    {
    public:
      void setCallback(CallbackType callback);
      void setData(typename Utilspp::TypeTrait< DataType >::ParamType data);
    };
  }
}

#include "StorageOptions.inl"

#endif
