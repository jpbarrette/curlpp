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

#include "global.h"
#include "Exception.hpp"

cURLpp::RuntimeError::~RuntimeError() throw()
{}

cURLpp::RuntimeError::RuntimeError( const char *reason )
    : std::runtime_error(std::string(reason))
{}

cURLpp::RuntimeError::RuntimeError( const std::string &reason )
    : std::runtime_error(reason)
{}

cURLpp::LogicError::~LogicError() throw()
{}

cURLpp::LogicError::LogicError( const char *reason )
    : std::logic_error(std::string(reason))
{}

cURLpp::LogicError::LogicError( const std::string &reason )
    : std::logic_error(reason)
{}

cURLpp::LibcurlRuntimeError::LibcurlRuntimeError( const std::string &reason, CURLcode code )
    : cURLpp::RuntimeError(reason)
    , mCode(code)
{}

cURLpp::LibcurlRuntimeError::LibcurlRuntimeError( const char *reason, CURLcode code )
    : cURLpp::RuntimeError(reason)
    , mCode(code)
{}

CURLcode cURLpp::LibcurlRuntimeError::whatCode() const throw()
{
   return mCode;
}

cURLpp::LibcurlLogicError::LibcurlLogicError( const std::string &reason, CURLcode code )
    : cURLpp::LogicError(reason)
    , mCode(code)
{}

cURLpp::LibcurlLogicError::LibcurlLogicError( const char *reason, CURLcode code )
    : cURLpp::LogicError(reason)
    , mCode(code)
{}

cURLpp::UnsetOption::UnsetOption(const std::string &reason)
    : cURLpp::RuntimeError(reason)
{};

cURLpp::UnsetOption::UnsetOption(const char *reason)
    : cURLpp::RuntimeError(reason)
{};

cURLpp::NotAvailable::NotAvailable()
    : cURLpp::LogicError("This option was not available at compile time.")
{};

cURLpp::UnknowException::UnknowException() 
  : cURLpp::RuntimeError("An unknown exception was thrown within a callback")
{}

CURLcode cURLpp::LibcurlLogicError::whatCode() const throw()
{
   return mCode;
}

cURLpp::CallbackExceptionBase::CallbackExceptionBase() 
  : RuntimeError("Exception thrown within a callback")
{}
    
cURLpp::CallbackExceptionBase::CallbackExceptionBase(const CallbackExceptionBase &other) 
  : RuntimeError(other)
{}


void cURLpp::libcurlRuntimeAssert( const std::string &reason, CURLcode code )
{
  if ( code != CURLE_OK )
   {
      throw cURLpp::LibcurlRuntimeError( reason, code );
   }
}

void cURLpp::libcurlRuntimeAssert(const char *reason, CURLcode code)
{
  libcurlRuntimeAssert(std::string(reason), code);
}

void cURLpp::libcurlLogicAssert( const std::string &reason, CURLcode code )
{
  if ( code != CURLE_OK )
   {
      throw cURLpp::LibcurlLogicError( reason, code );
   }
}

void cURLpp::libcurlLogicAssert( const char *reason, CURLcode code )
{
    libcurlLogicAssert(std::string(reason), code);
}

void cURLpp::runtimeAssert( const std::string &reason, bool isOkay )
{
   if ( !isOkay )
   {
      throw cURLpp::RuntimeError( reason );
   }
}

void cURLpp::runtimeAssert( const char *reason, bool isOkay )
{
    runtimeAssert(std::string(reason), isOkay);
}

void cURLpp::logicAssert( const std::string &reason, bool isOkay )
{
   if ( !isOkay )
   {
      throw cURLpp::LogicError( reason );
   }
}

void cURLpp::logicAssert( const char *reason, bool isOkay )
{
    logicAssert(std::string(reason), isOkay);
}

