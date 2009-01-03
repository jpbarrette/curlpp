/*
*    Copyright (c) <2002-2009> <Jean-Philippe Barrette-LaPierre>
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

#include <string>
#include <iostream>

#include "utilspp/Functors.hpp"

#include "curlpp/global.h"
#include "curlpp/CurlHandle.hpp"
#include "curlpp/internal/OptionSetter.hpp"


namespace curlpp
{

namespace internal
{

	
struct Callbacks
{
	static size_t 
	WriteCallback(char * buffer, size_t size, size_t nitems, curlpp::CurlHandle * handle)
	{
		return handle->executeWriteFunctor(buffer, size, nitems);
	};


	static size_t
	StreamWriteCallback(char * buffer, size_t size, size_t nitems, std::ostream * stream)
	{
		size_t realwrote = size * nitems;
		stream->write(buffer, static_cast<std::streamsize>(realwrote));
		if(!(*stream))
			realwrote = 0;

		return realwrote;
	};


	static size_t
	HeaderCallback(char * buffer, size_t size, size_t nitems, curlpp::CurlHandle * handle)
	{
		return handle->executeHeaderFunctor(buffer, size, nitems);
	};


	static size_t
	ReadCallback(char * buffer, size_t size, size_t nitems, curlpp::CurlHandle * handle)
	{
		return handle->executeReadFunctor(buffer, size, nitems);
	};


	static size_t
	StreamReadCallback(char * buffer, size_t size, size_t nitems, std::istream * stream)
	{
		size_t realread = stream->readsome(buffer, static_cast<std::streamsize>(size * nitems));
		if(!(*stream))
			realread = CURL_READFUNC_ABORT;

		return realread;
	};


	static int
	ProgressCallback(curlpp::CurlHandle * handle, 
											double dltotal, 
											double dlnow, 
											double ultotal, 
											double ulnow)
	{
		return handle->executeProgressFunctor(dltotal, dlnow, ultotal, ulnow);
	};


	static int
	DebugCallback(CURL *,
									curl_infotype type,
									char * data,
									size_t size,
									curlpp::CurlHandle * handle)
	{
		return handle->executeDebugFunctor(type, data, size);
	};


	static CURLcode 
	SslCtxCallback(CURL *,
										void * ssl_ctx,
										curlpp::CurlHandle * handle)
	{
		return handle->executeSslCtxFunctor(ssl_ctx);
	};

};


}// namespace internal

}// namespace curlpp



void
curlpp::internal::OptionSetter<curlpp::Forms, CURLOPT_HTTPPOST>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_HTTPPOST, value.cHttpPost());
};


void
curlpp::internal::OptionSetter<curlpp::types::WriteFunctionFunctor, CURLOPT_WRITEFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_WRITEFUNCTION, Callbacks::WriteCallback);
	handle->option(CURLOPT_WRITEDATA, handle);
	handle->setWriteFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostWriteFunction, CURLOPT_WRITEFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_WRITEFUNCTION, Callbacks::WriteCallback);
	handle->option(CURLOPT_WRITEDATA, handle);
	handle->setWriteFunctor(curlpp::types::WriteFunctionFunctor(&value,
		&curlpp::types::BoostWriteFunction::operator()));
};

#endif


void
curlpp::internal::OptionSetter<FILE *, CURLOPT_WRITEDATA>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_WRITEFUNCTION, (void *)NULL);
	handle->option(CURLOPT_WRITEDATA, value);
};


void
curlpp::internal::OptionSetter<std::ostream *, CURLOPT_WRITEDATA>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_WRITEFUNCTION, (void *)Callbacks::StreamWriteCallback);
	handle->option(CURLOPT_WRITEDATA, value);
};


void
curlpp::internal::OptionSetter<curlpp::types::ReadFunctionFunctor, CURLOPT_READFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_READFUNCTION, Callbacks::ReadCallback);
	handle->option(CURLOPT_READDATA, handle);
	handle->setReadFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostReadFunction, CURLOPT_READFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_READFUNCTION, Callbacks::ReadCallback);
	handle->option(CURLOPT_READDATA, handle);
	handle->setReadFunctor(value);
};

#endif


void
curlpp::internal::OptionSetter<FILE *, CURLOPT_READDATA>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_READFUNCTION, (void *)NULL);
	handle->option(CURLOPT_READDATA, value);
};


void
curlpp::internal::OptionSetter<std::istream *, CURLOPT_READDATA>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_READFUNCTION, (void *)Callbacks::StreamReadCallback);
	handle->option(CURLOPT_READDATA, value);
};


void
curlpp::internal::OptionSetter<curlpp::types::ProgressFunctionFunctor, CURLOPT_PROGRESSFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_PROGRESSFUNCTION, Callbacks::ProgressCallback);
	handle->option(CURLOPT_PROGRESSDATA, handle);
	handle->setProgressFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostProgressFunction, CURLOPT_PROGRESSFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_PROGRESSFUNCTION, Callbacks::ProgressCallback);
	handle->option(CURLOPT_PROGRESSDATA, handle);
	handle->setProgressFunctor(value);
};

#endif


void
curlpp::internal::OptionSetter<curlpp::types::WriteFunctionFunctor, CURLOPT_HEADERFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_HEADERFUNCTION, Callbacks::HeaderCallback);
	handle->option(CURLOPT_HEADERDATA, handle);
	handle->setHeaderFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostWriteFunction, CURLOPT_HEADERFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_HEADERFUNCTION, Callbacks::HeaderCallback);
	handle->option(CURLOPT_HEADERDATA, handle);
	handle->setHeaderFunctor(value);
};

#endif


void
curlpp::internal::OptionSetter<curlpp::types::DebugFunctionFunctor, CURLOPT_DEBUGFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_DEBUGFUNCTION, Callbacks::DebugCallback);
	handle->option(CURLOPT_DEBUGDATA, handle);
	handle->setDebugFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostDebugFunction, CURLOPT_DEBUGFUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_DEBUGFUNCTION, Callbacks::DebugCallback);
	handle->option(CURLOPT_DEBUGDATA, handle);
	handle->setDebugFunctor(value);
};

#endif


void
curlpp::internal::OptionSetter<curlpp::types::SslCtxFunctionFunctor, CURLOPT_SSL_CTX_FUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_SSL_CTX_FUNCTION, Callbacks::SslCtxCallback);
	handle->option(CURLOPT_SSL_CTX_DATA, handle);
	handle->setSslCtxFunctor(value);
};


#ifdef HAVE_BOOST

void
curlpp::internal::OptionSetter<curlpp::types::BoostSslCtxFunction, CURLOPT_SSL_CTX_FUNCTION>
::setOpt(curlpp::CurlHandle * handle, ParamType value)
{
	handle->option(CURLOPT_SSL_CTX_FUNCTION, Callbacks::SslCtxCallback);
	handle->option(CURLOPT_SSL_CTX_DATA, handle);
	handle->setSslCtxFunctor(value);
};

#endif
