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


#ifndef CURLPP_INFOS_HPP
#define CURLPP_INFOS_HPP

#include "Info.hpp"

namespace cURLpp
{
  namespace Infos
  {
    typedef cURLpp::Info< CURLINFO_EFFECTIVE_URL, std::string > EffectiveUrl;
    typedef cURLpp::Info< CURLINFO_RESPONSE_CODE, long > ResponseCode;
    typedef cURLpp::Info< CURLINFO_HTTP_CONNECTCODE, long > HttpConnectCode;
    typedef cURLpp::Info< CURLINFO_FILETIME, long > FileTime;
    typedef cURLpp::Info< CURLINFO_TOTAL_TIME, double > TotalTime;
    typedef cURLpp::Info< CURLINFO_NAMELOOKUP_TIME, double > NameLookupTime;
    typedef cURLpp::Info< CURLINFO_CONNECT_TIME, double > ConnectTime;
    typedef cURLpp::Info< CURLINFO_PRETRANSFER_TIME, double > PreTransferTime;
    typedef cURLpp::Info< CURLINFO_STARTTRANSFER_TIME, double > StartTransferTime;
    typedef cURLpp::Info< CURLINFO_REDIRECT_TIME, double > RedirectTime;
    typedef cURLpp::Info< CURLINFO_REDIRECT_COUNT, long > RedirectCount;
    typedef cURLpp::Info< CURLINFO_SIZE_UPLOAD, double > SizeUpload;
    typedef cURLpp::Info< CURLINFO_SIZE_DOWNLOAD, double > SizeDownload;
    typedef cURLpp::Info< CURLINFO_SPEED_DOWNLOAD, double > SpeedDownload;
    typedef cURLpp::Info< CURLINFO_SPEED_UPLOAD, double > SpeedUpload;
    typedef cURLpp::Info< CURLINFO_HEADER_SIZE, long > HeaderSize;
    typedef cURLpp::Info< CURLINFO_REQUEST_SIZE, long > RequestSize;
    typedef cURLpp::Info< CURLINFO_SSL_VERIFYRESULT, long > SslVerifyResult;
    typedef cURLpp::Info< CURLINFO_SSL_ENGINES, std::list< std::string> > SslEngines;
    typedef cURLpp::Info< CURLINFO_CONTENT_LENGTH_DOWNLOAD, double > ContentLengthDownload;
    typedef cURLpp::Info< CURLINFO_CONTENT_LENGTH_UPLOAD, double > ContentLengthUpload;
    typedef cURLpp::Info< CURLINFO_CONTENT_TYPE, std::string > ContentType;
    typedef cURLpp::Info< CURLINFO_HTTPAUTH_AVAIL, long > HttpAuthAvail;
    typedef cURLpp::Info< CURLINFO_PROXYAUTH_AVAIL, long > ProxyAuthAvail;
    typedef cURLpp::Info< CURLINFO_OS_ERRNO, long > OsErrno;
    typedef cURLpp::Info< CURLINFO_NUM_CONNECTS, long > NumConnects;
#ifdef CURLINFO_COOKIELIST
    typedef cURLpp::Info< CURLINFO_COOKIELIST, std::list< std::string > > CookieList;
#endif
  };
};

#endif
