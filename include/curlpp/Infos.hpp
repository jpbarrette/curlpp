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


#ifndef CURLPP_INFOS_HPP
#define CURLPP_INFOS_HPP


#include "Info.hpp"

#include <curl/curl.h>

#include <list>


namespace curlpp
{


namespace infos
{


	typedef curlpp::Info<CURLINFO_EFFECTIVE_URL, std::string> EffectiveUrl;
	typedef curlpp::Info<CURLINFO_RESPONSE_CODE> ResponseCode;
	typedef curlpp::Info<CURLINFO_HTTP_CONNECTCODE> HttpConnectCode;
	typedef curlpp::Info<CURLINFO_FILETIME> FileTime;
	typedef curlpp::Info<CURLINFO_FILETIME_T> FileTimeT;
	typedef curlpp::Info<CURLINFO_TOTAL_TIME> TotalTime;
	typedef curlpp::Info<CURLINFO_NAMELOOKUP_TIME> NameLookupTime;
	typedef curlpp::Info<CURLINFO_CONNECT_TIME> ConnectTime;
	typedef curlpp::Info<CURLINFO_PRETRANSFER_TIME> PreTransferTime;
	typedef curlpp::Info<CURLINFO_STARTTRANSFER_TIME> StartTransferTime;
	typedef curlpp::Info<CURLINFO_REDIRECT_TIME> RedirectTime;
	typedef curlpp::Info<CURLINFO_REDIRECT_COUNT> RedirectCount;
	typedef curlpp::Info<CURLINFO_SIZE_UPLOAD> SizeUpload;
	typedef curlpp::Info<CURLINFO_SIZE_UPLOAD_T> SizeUploadT;
	typedef curlpp::Info<CURLINFO_SIZE_DOWNLOAD> SizeDownload;
	typedef curlpp::Info<CURLINFO_SIZE_DOWNLOAD_T> SizeDownloadT;
	typedef curlpp::Info<CURLINFO_SPEED_DOWNLOAD> SpeedDownload;
	typedef curlpp::Info<CURLINFO_SPEED_DOWNLOAD_T> SpeedDownloadT;
	typedef curlpp::Info<CURLINFO_SPEED_UPLOAD> SpeedUpload;
	typedef curlpp::Info<CURLINFO_SPEED_UPLOAD_T> SpeedUploadT;
	typedef curlpp::Info<CURLINFO_HEADER_SIZE> HeaderSize;
	typedef curlpp::Info<CURLINFO_REQUEST_SIZE> RequestSize;
	typedef curlpp::Info<CURLINFO_SSL_VERIFYRESULT> SslVerifyResult;
#if LIBCURL_VERSION_NUM >= 0x070c03
	typedef curlpp::Info<CURLINFO_SSL_ENGINES, std::list<std::string> > SslEngines;
#endif
	typedef curlpp::Info<CURLINFO_CONTENT_LENGTH_DOWNLOAD> ContentLengthDownload;
	typedef curlpp::Info<CURLINFO_CONTENT_LENGTH_DOWNLOAD_T> ContentLengthDownloadT;
	typedef curlpp::Info<CURLINFO_CONTENT_LENGTH_UPLOAD> ContentLengthUpload;
	typedef curlpp::Info<CURLINFO_CONTENT_LENGTH_UPLOAD_T> ContentLengthUploadT;
	typedef curlpp::Info<CURLINFO_CONTENT_TYPE, std::string> ContentType;
	typedef curlpp::Info<CURLINFO_HTTPAUTH_AVAIL> HttpAuthAvail;
	typedef curlpp::Info<CURLINFO_PROXYAUTH_AVAIL> ProxyAuthAvail;
#if LIBCURL_VERSION_NUM >= 0x070c02
	typedef curlpp::Info<CURLINFO_OS_ERRNO> OsErrno;
#endif
#if LIBCURL_VERSION_NUM >= 0x070c03
	typedef curlpp::Info<CURLINFO_NUM_CONNECTS> NumConnects;
#endif

#if LIBCURL_VERSION_NUM >= 0x070e01
	typedef curlpp::Info<CURLINFO_COOKIELIST, std::list<std::string> > CookieList;
#else
#ifdef CURLPP_ALLOW_NOT_AVAILABLE
	// This curlinfo text must be specified, so we specify something
	// that we know will be there.
	typedef curlpp::NotAvailableInfo<CURLINFO_EFFECTIVE_URL, std::list<std::string> > CookieList;
#endif
#endif


} // namespace infos

namespace Infos = infos;


} // namespace curlpp

namespace cURLpp = curlpp;


#endif // #ifndef CURLPP_INFOS_HPP
