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

#include <iostream>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdarg>

#ifdef HAVE_CONFIG_H
#include <global.h>
#endif //HAVE_CONFIG

#include "curlpp/curlpp.hpp"
#include "curlpp/Storage.hpp"


curlpp::BodyStorage::BodyStorage(
   curlpp::Curl * parent,
   curlpp::OutputTrait * trait,
   bool own
)
      :
      StorageBase<curlpp::OutputTrait>(parent, trait, &stdoutTrait, own)
{}

size_t curlpp::BodyStorage::writeCallback(
   void * buffer,
   size_t size,
   size_t nitems,
   void * outstream
)
{
   curlpp::OutputTrait * trait = static_cast< curlpp::OutputTrait *>(outstream);
   return trait->write(buffer, size * nitems);
}

void curlpp::BodyStorage::setCallback()
{
   mParent->writeFunction(&writeCallback);
}

void curlpp::BodyStorage::setCallbackData()
{
   mParent->writeData(mTrait);
}

void curlpp::HeaderStorage::setCallback()
{
   mParent->writeHeaderFunction(&writeCallback);
}

void curlpp::HeaderStorage::setCallbackData()
{
   mParent->writeHeaderData(mTrait);
}

size_t curlpp::HeaderStorage::writeCallback(
   void * buffer,
   size_t size,
   size_t nitems,
   void * outstream
)
{
   curlpp::OutputTrait * trait = static_cast< curlpp::OutputTrait *>(outstream);
   return trait->write(buffer, size * nitems);
}

void curlpp::InputStorage::setCallbackData()
{
   mParent->readData(mTrait);
}

void curlpp::InputStorage::setCallback()
{
   mParent->readFunction(&readCallback);
}

size_t curlpp::InputStorage::readCallback(
   void * buffer,
   size_t size,
   size_t nmemb,
   void * instream
)
{
   curlpp::InputTrait * trait = static_cast< curlpp::InputTrait *>(instream);
   return trait->read(buffer, size * nmemb);
}

void curlpp::ProgressStorage::setCallback()
{
   mParent->progressFunction(&progressCallback);
}

void curlpp::ProgressStorage::setCallbackData()
{
   mParent->progressData(mTrait);
}

int curlpp::ProgressStorage::progressCallback(
   void * clientp,
   double dltotal,
   double dlnow,
   double ultotal,
   double ulnow
)
{
   curlpp::ProgressTrait * trait = static_cast< curlpp::ProgressTrait *>(clientp);
   return !(trait->progressFunction( dltotal, dlnow, ultotal, ulnow ));
}

void curlpp::PasswdStorage::setCallback()
{
   mParent->passwdFunction(&passwdCallback);
}

void curlpp::PasswdStorage::setCallbackData()
{
   mParent->passwdData(mTrait);
}

int curlpp::PasswdStorage::passwdCallback(
   void * client,
   char * prompt,
   char * buffer,
   int buflen
)
{
   curlpp::PasswdTrait * trait = static_cast<curlpp::PasswdTrait *>(client);
   return !(trait->passwdFunction(prompt, buffer, buflen));
}

void curlpp::DebugStorage::setCallback()
{
   mParent->debugFunction(&debugCallback);
}

void curlpp::DebugStorage::setCallbackData()
{
   mParent->debugData(mTrait);
}

int curlpp::DebugStorage::debugCallback(
   CURL *,
   curlpp::debug::Type type,
   char * buffer,
   size_t len,
   void * ptr
)
{
   curlpp::DebugTrait * trait = static_cast<curlpp::DebugTrait *>(ptr);
   trait->debugFunction(type, buffer, len);
   return 0;
}

#if LIBCURL_VERSION_NUM >= 0x070b01
curlpp::Storage<curlpp::PasswdStorage>::Storage(curlpp::Curl *)
{}

void curlpp::Storage<curlpp::PasswdStorage>::trait(curlpp::PasswdTrait *, bool)
{
  curlpp::runtimeAssert(false, "The CURLOPT_PASSWDFUNCTION option has been deprecated.");
}
#endif

