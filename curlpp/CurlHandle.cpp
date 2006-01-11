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

#include <string>
#include <iostream>

#include "global.h"
#include "CurlHandle.hpp"

#include "cURLpp.hpp"
#include "Exception.hpp"


void cURLpp::CurlHandle::perform()
{
  CURLcode code;

  code = curl_easy_perform( mCurl );
  throwException();
  libcurlRuntimeAssert(mErrorBuffer, code); //if we got an error
}

CURL *
cURLpp::CurlHandle::getHandle()
{
  return mCurl;
}

cURLpp::CurlHandle::CurlHandle() 
  : mWriteFunctor(NULL)
  , mHeaderFunctor(NULL)
  , mReadFunctor(NULL)
  , mProgressFunctor(NULL)
  , mDebugFunctor(NULL)
  , mSslFunctor(NULL)
  ,mException(NULL)
{
  mCurl = curl_easy_init();
  runtimeAssert( "Error when trying to curl_easy_init() a handle", mCurl );
  errorBuffer( mErrorBuffer );
}

cURLpp::CurlHandle::~CurlHandle()
{
  if(mException) {
    delete mException;
    mException = NULL;
  }
  curl_easy_cleanup(mCurl);
}

void
cURLpp::CurlHandle::errorBuffer(char *buffer)
{
  option( CURLOPT_ERRORBUFFER, (void *)buffer);
}

size_t 
cURLpp::CurlHandle::executeWriteFunctor(char *buffer, size_t size, size_t nitems)
{
  if(mWriteFunctor) {
    try {
      return (*mWriteFunctor)(buffer, size, nitems);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return 0;
}

size_t 
cURLpp::CurlHandle::executeHeaderFunctor(char *buffer, size_t size, size_t nitems)
{
  if(mHeaderFunctor) {
    try {
      return (*mHeaderFunctor)(buffer, size, nitems);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return 0;
}

size_t 
cURLpp::CurlHandle::executeReadFunctor(char *buffer, size_t size, size_t nitems)
{
  if(mReadFunctor) {
    try {
      return (*mReadFunctor)(buffer, size, nitems);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return 0;
}

int 
cURLpp::CurlHandle::executeProgressFunctor(double dltotal, 
					   double dlnow, 
					   double ultotal, 
					   double ulnow)
{
  if(mProgressFunctor) {
    try {
      return (*mProgressFunctor)(dltotal, dlnow, ultotal, ulnow);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return -1;
}

int 
cURLpp::CurlHandle::executeDebugFunctor(curl_infotype info, char *buffer, size_t size)
{
  if(mDebugFunctor) {
    try {
      return (*mDebugFunctor)(info, buffer, size);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return -1;
}

CURLcode 
cURLpp::CurlHandle::executeSslCtxFunctor(void *ssl_ctx)
{
  if(mSslFunctor) {
    try {
      return (*mSslFunctor)(ssl_ctx);
    }
    catch(cURLpp::CallbackExceptionBase *e) {
      setException(e);
    }
    catch(...) {
      setException(new CallbackException< cURLpp::UnknowException >(cURLpp::UnknowException()));
    }
  }
  
  return CURLE_ABORTED_BY_CALLBACK;
}

void
cURLpp::CurlHandle::setException(cURLpp::CallbackExceptionBase *e) 
{
  if(mException) {
    delete mException;
  }

  mException = e;
}

void
cURLpp::CurlHandle::throwException()
{
  if(mException) {
    mException->throwMe();
  }
}


