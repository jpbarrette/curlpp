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

#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef HAVE_CONFIG_H
#include <global.h>
#endif //HAVE_CONFIG

#include "cURLpp.hpp"


cURLpp::BodyStorage::BodyStorage(
   cURLpp::Curl *parent,
   cURLpp::OutputTrait *trait,
   bool own
)
      :
      StorageBase< cURLpp::OutputTrait >( parent, trait, &stdoutTrait, own )
{}

size_t cURLpp::BodyStorage::writeCallback(
   void *buffer,
   size_t size,
   size_t nitems,
   void *outstream
)
{
   cURLpp::OutputTrait * trait = static_cast< cURLpp::OutputTrait *>( outstream );
   return trait->write( buffer, size * nitems );
}

void cURLpp::BodyStorage::setCallback()
{
   mParent->writeFunction( &writeCallback );
}

void cURLpp::BodyStorage::setCallbackData()
{
   mParent->writeData( mTrait );
}

void cURLpp::HeaderStorage::setCallback()
{
   mParent->writeHeaderFunction( &writeCallback );
}

void cURLpp::HeaderStorage::setCallbackData()
{
   mParent->writeHeaderData( mTrait );
}

size_t cURLpp::HeaderStorage::writeCallback(
   void *buffer,
   size_t size,
   size_t nitems,
   void *outstream
)
{
   cURLpp::OutputTrait * trait = static_cast< cURLpp::OutputTrait *>( outstream );
   return trait->write( buffer, size * nitems );
}

void cURLpp::InputStorage::setCallbackData()
{
   mParent->readData( mTrait );
}

void cURLpp::InputStorage::setCallback()
{
   mParent->readFunction( &readCallback );
}

size_t cURLpp::InputStorage::readCallback(
   void *buffer,
   size_t size,
   size_t nmemb,
   void *instream
)
{
   cURLpp::InputTrait * trait = static_cast< cURLpp::InputTrait *>( instream );
   return trait->read( buffer, size * nmemb );
}

void cURLpp::ProgressStorage::setCallback()
{
   mParent->progressFunction( &progressCallback );
}

void cURLpp::ProgressStorage::setCallbackData()
{
   mParent->progressData( mTrait );
}

int cURLpp::ProgressStorage::progressCallback(
   void *clientp,
   double dltotal,
   double dlnow,
   double ultotal,
   double ulnow
)
{
   cURLpp::ProgressTrait * trait = static_cast< cURLpp::ProgressTrait *>( clientp );
   return !( trait->progressFunction( dltotal, dlnow, ultotal, ulnow ) );
}

void cURLpp::PasswdStorage::setCallback()
{
   mParent->passwdFunction( &passwdCallback );
}

void cURLpp::PasswdStorage::setCallbackData()
{
   mParent->passwdData( mTrait );
}

int cURLpp::PasswdStorage::passwdCallback(
   void *client,
   char *prompt,
   char *buffer,
   int buflen
)
{
   cURLpp::PasswdTrait * trait = static_cast< cURLpp::PasswdTrait * >( client );
   return !( trait->passwdFunction( prompt, buffer, buflen ) );
}

void cURLpp::DebugStorage::setCallback()
{
   mParent->debugFunction( &debugCallback );
}

void cURLpp::DebugStorage::setCallbackData()
{
   mParent->debugData( mTrait );
}

int cURLpp::DebugStorage::debugCallback(
   CURL *,
   cURLpp::debug::Type type,
   char *buffer,
   size_t len,
   void *ptr
)
{
   cURLpp::DebugTrait * trait = static_cast< cURLpp::DebugTrait * >( ptr );
   trait->debugFunction( type, buffer, len );
   return 0;
}

#if LIBCURL_VERSION_NUM >= 0x070b01
cURLpp::Storage< cURLpp::PasswdStorage >::Storage( cURLpp::Curl * )
{}

void cURLpp::Storage< cURLpp::PasswdStorage >::trait( cURLpp::PasswdTrait *, bool )
{
  cURLpp::runtimeAssert( false, "The CURLOPT_PASSWDFUNCTION option has been deprecated." );
}
#endif

