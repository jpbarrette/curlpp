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

#ifndef CURLPP_CURLHANDLE_HPP
#define CURLPP_CURLHANDLE_HPP

#include <memory>
#include <curl/curl.h>

#include "dllfct.h"
#include "Exception.hpp"
#include "Types.hpp"

namespace cURLpp
{
  class CurlHandle
  {
  public:
    CURLPPAPI CurlHandle();
    CURLPPAPI CurlHandle(CURL * handle);

    std::auto_ptr< CurlHandle > CURLPPAPI clone() const;

    /**
     * Simply calls curl_easy_perform on the handle,
     * but throws exceptions on errors.
     */
    void CURLPPAPI perform();

    /**
     * Simply calls curl_easy_reset on the handle
     */
    void CURLPPAPI reset();

    virtual CURLPPAPI ~CurlHandle();

    /**
     * Calls curl_easy_setopt on the option.
     */
    template< typename OptionType >
    void option(CURLoption option, OptionType value);
      
    /**
     * Calls curl_easy_setopt on the option.
     */
    template< typename OptionType, CURLoption optionType >
    void option(OptionType value);

    /**
     * This function will return the cURL * handle.
     * DO NOT use this, unless you REALLY know what you
     * are doing.
     */
   CURLPPAPI CURL *  getHandle() const;

    /**
     * Request internal information from the curl session 
     * with this function. The third argument MUST be a 
     * pointer to a long, a pointer to a char *, a pointer 
     * to a struct curl_slist * or a pointer to a double.
     */
    template < typename T >
    void getInfo(CURLINFO info, T &value);

    size_t executeWriteFunctor(char *buffer, size_t size, size_t nitems);
    void setWriteFunctor(cURLpp::Types::WriteFunctionFunctor functor)
    {mWriteFunctor = functor;}

    size_t executeHeaderFunctor(char *buffer, size_t size, size_t nitems);
    void setHeaderFunctor(cURLpp::Types::WriteFunctionFunctor functor)
    {mHeaderFunctor = functor;}

    size_t executeReadFunctor(char *buffer, size_t size, size_t nitems);
    void setReadFunctor(cURLpp::Types::ReadFunctionFunctor functor)
    {mReadFunctor = functor;}

    int executeProgressFunctor(double dltotal, 
			       double dlnow, 
			       double ultotal, 
			       double ulnow);
    void setProgressFunctor(cURLpp::Types::ProgressFunctionFunctor functor)
    {mProgressFunctor = functor;}

    int executeDebugFunctor(curl_infotype, char *, size_t);
    void setDebugFunctor(cURLpp::Types::DebugFunctionFunctor functor)
    {mDebugFunctor = functor;}

    CURLcode executeSslCtxFunctor(void *ssl_ctx);
    void setSslCtxFunctor(cURLpp::Types::SslCtxFunctionFunctor functor)
    {mSslFunctor = functor;}
    
    void setException(cURLpp::CallbackExceptionBase *e);
    void throwException();

  private:
    CURLPPAPI CurlHandle(const CurlHandle &other);
    CURLPPAPI CurlHandle& operator=(const CurlHandle &other);

    /**
     * Pass a char * to a buffer that the libcURL may store
     * human readable error messages in. This may  be  more
     * helpful  than just the return code from the library.
     * The buffer must be at least CURL_ERROR_SIZE big.
     * Note: if the library does not return an  error,  the
     * buffer may not have been touched. Do not rely on the
     * contents in those cases.
     */
    void CURLPPAPI errorBuffer(char* buffer);
    
    
  private:
    CURL *mCurl;
    
    char mErrorBuffer[CURL_ERROR_SIZE + 1];

    
    cURLpp::Types::WriteFunctionFunctor mWriteFunctor;
    cURLpp::Types::WriteFunctionFunctor mHeaderFunctor;
    cURLpp::Types::ReadFunctionFunctor mReadFunctor;
    cURLpp::Types::ProgressFunctionFunctor mProgressFunctor;
    cURLpp::Types::DebugFunctionFunctor mDebugFunctor;
    cURLpp::Types::SslCtxFunctionFunctor mSslFunctor;
    cURLpp::CallbackExceptionBase * mException;
  };
}

#include "CurlHandle.inl"

#endif
