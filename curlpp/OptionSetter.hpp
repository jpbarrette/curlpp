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

#ifndef CURLPP_OPTIONSETTER_HPP
#define CURLPP_OPTIONSETTER_HPP

#include "dllfct.h"

#include "OptionContainer.hpp"
#include "CurlHandle.hpp"
#include "Types.hpp"

namespace cURLpp
{
  /**
   * This class is used to specialize some option settings.
   */
  template< typename OptionValueType, CURLoption optionType >
  class CURLPPAPI OptionSetter
  {
  public:
    typedef typename OptionContainer< OptionValueType >::HandleOptionType ParamType;

    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  /**
   * This class is used to specialize the std::string options type.
   */
  template< CURLoption optionType >
  class CURLPPAPI OptionSetter< std::string, optionType >
  {
  public:
    typedef cURLpp::OptionContainerType< std::string >::HandleOptionType ParamType;
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  /**
   * This class is used to specialize the cURLpp::SList options type.
   */
  template< CURLoption optionType >
  class CURLPPAPI OptionSetter< std::list< std::string >, optionType >
  {
  public:
    typedef std::list< std::string > OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  /**
   * This class is used to specialize the cURLpp::HttpPost options type.
   */
  template< >
  class CURLPPAPI OptionSetter< std::list< cURLpp::FormPart * >, 
				CURLOPT_HTTPPOST >
  {
  public:
    typedef std::list< cURLpp::FormPart * > OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::WriteFunctionFunctor, 
				CURLOPT_WRITEFUNCTION >
  {
  public:
    typedef cURLpp::Types::WriteFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostWriteFunction, 
				CURLOPT_WRITEFUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostWriteFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

  template< >
  class CURLPPAPI OptionSetter< FILE *, 
				CURLOPT_WRITEDATA >
  {
  public:
    typedef FILE * OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::ReadFunctionFunctor, 
				CURLOPT_READFUNCTION >
  {
  public:
    typedef cURLpp::Types::ReadFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostReadFunction, 
				CURLOPT_READFUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostReadFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

  template< >
  class CURLPPAPI OptionSetter< FILE *, 
				CURLOPT_READDATA >
  {
  public:
    typedef FILE * OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::ProgressFunctionFunctor, 
				CURLOPT_PROGRESSFUNCTION >
  {
  public:
    typedef cURLpp::Types::ProgressFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostProgressFunction, 
				CURLOPT_PROGRESSFUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostProgressFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::WriteFunctionFunctor, 
				CURLOPT_HEADERFUNCTION >
  {
  public:
    typedef cURLpp::Types::WriteFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostWriteFunction, 
				CURLOPT_HEADERFUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostWriteFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::DebugFunctionFunctor, 
				CURLOPT_DEBUGFUNCTION >
  {
  public:
    typedef cURLpp::Types::DebugFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostDebugFunction, 
				CURLOPT_DEBUGFUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostDebugFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::SslCtxFunctionFunctor, 
				CURLOPT_SSL_CTX_FUNCTION >
  {
  public:
    typedef cURLpp::Types::SslCtxFunctionFunctor OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };

#ifdef HAVE_BOOST
  template< >
  class CURLPPAPI OptionSetter< cURLpp::Types::BoostSslCtxFunction, 
				CURLOPT_SSL_CTX_FUNCTION >
  {
  public:
    typedef cURLpp::Types::BoostSslCtxFunction OptionValueType;
    typedef cURLpp::OptionContainerType< OptionValueType >::HandleOptionType ParamType;
    
    static void setOpt(cURLpp::CurlHandle *handle, ParamType value);
  };
#endif

}

#include "OptionSetter.inl"

#endif

