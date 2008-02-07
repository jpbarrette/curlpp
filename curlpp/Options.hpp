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


#include "Option.hpp"
//#include "StorageOptions.hpp"

#include <iostream> 

namespace cURLpp
{
  namespace Options
  {
    /**
     * Cookie interface.
     */
#ifdef CURLOPT_COOKIELIST
    typedef cURLpp::OptionTrait< std::string, CURLOPT_COOKIELIST > CookieList;
#else
#ifdef CURLPP_ALLOW_NOT_AVAILABLE
    typedef cURLpp::NotAvailableOptionTrait< std::string > CookieList;
#endif
#endif
    /**
     * Behavior options.
     */
    typedef cURLpp::OptionTrait< bool, CURLOPT_VERBOSE > Verbose;
    typedef cURLpp::OptionTrait< bool, CURLOPT_HEADER > Header;
    typedef cURLpp::OptionTrait< bool, CURLOPT_NOSIGNAL > NoSignal;
    typedef cURLpp::OptionTrait< bool, CURLOPT_NOPROGRESS > NoProgress;
    
    /**
     * Callback options. 
     */
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::WriteFunctionFunctor, 
      CURLOPT_WRITEFUNCTION > WriteFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostWriteFunction, 
      CURLOPT_WRITEFUNCTION > BoostWriteFunction;
#endif

    /**
     * Using this option will reset CURLOPT_WRITEFUNCTION to 
     * default callback. In fact, use only this option if you only 
     * want libcURL to use the FILE * given in argument instead 
     * of stdout. 
     */
    typedef cURLpp::OptionTrait< FILE *, CURLOPT_WRITEDATA > WriteFile;
    typedef cURLpp::OptionTrait< std::ostream *, CURLOPT_WRITEDATA > WriteStream;

    typedef cURLpp::OptionTrait< 
      cURLpp::Types::ReadFunctionFunctor, 
      CURLOPT_READFUNCTION > ReadFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostReadFunction, 
      CURLOPT_READFUNCTION > BoostReadFunction;
#endif
    
    /**
     * Using this option will reset CURLOPT_READFUNCTION to 
     * default callback. In fact, use only this option if you only 
     * want libcURL to use the FILE * given in argument instead 
     * of stdout. 
     */
    typedef cURLpp::OptionTrait< FILE *, CURLOPT_READDATA > ReadFile;
    typedef cURLpp::OptionTrait< std::istream *, CURLOPT_READDATA > ReadStream;

    typedef cURLpp::OptionTrait< 
      cURLpp::Types::ProgressFunctionFunctor, 
      CURLOPT_PROGRESSFUNCTION > ProgressFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostProgressFunction, 
      CURLOPT_PROGRESSFUNCTION > BoostProgressFunction;
#endif

    typedef cURLpp::OptionTrait< 
      cURLpp::Types::WriteFunctionFunctor, 
      CURLOPT_HEADERFUNCTION > HeaderFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostWriteFunction, 
      CURLOPT_HEADERFUNCTION > BoostHeaderFunction;
#endif

    typedef cURLpp::OptionTrait< 
      cURLpp::Types::DebugFunctionFunctor, 
      CURLOPT_DEBUGFUNCTION > DebugFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostDebugFunction, 
      CURLOPT_DEBUGFUNCTION > BoostDebugFunction;
#endif

    typedef cURLpp::OptionTrait< 
      cURLpp::Types::SslCtxFunctionFunctor,
      CURLOPT_SSL_CTX_FUNCTION > SslCtxFunction;

#ifdef HAVE_BOOST
    typedef cURLpp::OptionTrait< 
      cURLpp::Types::BoostSslCtxFunction,
      CURLOPT_SSL_CTX_FUNCTION > BoostSslCtxFunction;
#endif
    
      
    /**
     * Error options.
     */
    typedef cURLpp::OptionTrait< char *, CURLOPT_ERRORBUFFER > ErrorBuffer;
#ifdef FILE
    typedef cURLpp::OptionTrait< FILE *, CURLOPT_STDERR > StdErr;
#endif
    typedef cURLpp::OptionTrait< bool, CURLOPT_FAILONERROR > FailOnError;

    /**
     * Network options.
     */
    typedef cURLpp::OptionTrait< std::string, CURLOPT_URL > Url;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_PROXY > Proxy;
    typedef cURLpp::OptionTrait< long, CURLOPT_PROXYPORT > ProxyPort;
    typedef cURLpp::OptionTrait< curl_proxytype, CURLOPT_PROXYTYPE > ProxyType;
    typedef cURLpp::OptionTrait< bool, CURLOPT_HTTPPROXYTUNNEL > HttpProxyTunnel;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_INTERFACE > Interface;
    typedef cURLpp::OptionTrait< long, CURLOPT_DNS_CACHE_TIMEOUT > DnsCacheTimeout;
    typedef cURLpp::OptionTrait< bool, CURLOPT_DNS_USE_GLOBAL_CACHE > DnsUseGlobalCache;
    typedef cURLpp::OptionTrait< long, CURLOPT_BUFFERSIZE > BufferSize;
    typedef cURLpp::OptionTrait< long, CURLOPT_PORT > Port;

	typedef cURLpp::OptionTrait< bool, CURLOPT_TCP_NODELAY > TcpNoDelay;

    /**
     * Names and passwords options.
     */
    typedef cURLpp::OptionTrait< long, CURLOPT_NETRC > Netrc;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_NETRC_FILE > NetrcFile;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_USERPWD > UserPwd;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_PROXYUSERPWD > ProxyUserPwd;
    typedef cURLpp::OptionTrait< long, CURLOPT_HTTPAUTH > HttpAuth;
    typedef cURLpp::OptionTrait< long, CURLOPT_PROXYAUTH > ProxyAuth;

    /**
     * HTTP options.
     */
    typedef cURLpp::OptionTrait< bool, CURLOPT_AUTOREFERER > AutoReferer;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_ENCODING > Encoding;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FOLLOWLOCATION > FollowLocation;
    typedef cURLpp::OptionTrait< bool, CURLOPT_UNRESTRICTED_AUTH > UnrestrictedAuth;
    typedef cURLpp::OptionTrait< long, CURLOPT_MAXREDIRS > MaxRedirs;
    typedef cURLpp::OptionTrait< bool, CURLOPT_PUT > Put;
    typedef cURLpp::OptionTrait< bool, CURLOPT_UPLOAD > Upload;
    typedef cURLpp::OptionTrait< bool, CURLOPT_POST > Post;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_POSTFIELDS > PostFields;
    typedef cURLpp::OptionTrait< long, CURLOPT_POSTFIELDSIZE > PostFieldSize;
    typedef cURLpp::OptionTrait< curl_off_t, CURLOPT_POSTFIELDSIZE_LARGE > PostFieldSizeLarge;
    typedef cURLpp::OptionTrait< cURLpp::Forms, CURLOPT_HTTPPOST > HttpPost;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_REFERER > Referer;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_USERAGENT > UserAgent;
    typedef cURLpp::OptionTrait< std::list< std::string >, CURLOPT_HTTPHEADER > HttpHeader;
    typedef cURLpp::OptionTrait< std::list< std::string >, CURLOPT_HTTP200ALIASES > Http200Aliases;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_COOKIE > Cookie;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_COOKIEFILE > CookieFile;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_COOKIEJAR > CookieJar;
    typedef cURLpp::OptionTrait< bool, CURLOPT_COOKIESESSION > CookieSession;
    typedef cURLpp::OptionTrait< bool, CURLOPT_HTTPGET > HttpGet;
    typedef cURLpp::OptionTrait< long, CURLOPT_HTTP_VERSION > HttpVersion;

    /**
     * FTP options.
     */
    typedef cURLpp::OptionTrait< std::string, CURLOPT_FTPPORT > FtpPort;
    typedef cURLpp::OptionTrait< std::list< std::string >, CURLOPT_QUOTE > Quote;
    typedef cURLpp::OptionTrait< std::list< std::string >, CURLOPT_POSTQUOTE > PostQuote;
    typedef cURLpp::OptionTrait< std::list< std::string >, CURLOPT_PREQUOTE > PreQuote;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FTPLISTONLY > FtpListOnly;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FTPAPPEND > FtpAppend;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FTP_USE_EPSV > FtpUseEpsv;
#ifdef CURLOPT_FTP_FILEMETHOD
    typedef cURLpp::OptionTrait< long, CURLOPT_FTP_FILEMETHOD > FtpFileMethod;
#endif
    typedef cURLpp::OptionTrait< bool, CURLOPT_FTP_CREATE_MISSING_DIRS > FtpCreateMissingDirs;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FTP_RESPONSE_TIMEOUT > FtpResponseTimeout;
    typedef cURLpp::OptionTrait< curl_ftpssl, CURLOPT_FTP_SSL > FtpSsl;
    typedef cURLpp::OptionTrait< curl_ftpauth, CURLOPT_FTPSSLAUTH > FtpSslAuth;
      
    /**
     * Protocol options.
     */
    typedef cURLpp::OptionTrait< bool, CURLOPT_TRANSFERTEXT > TransferText;
    typedef cURLpp::OptionTrait< bool, CURLOPT_CRLF > Crlf;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_RANGE > Range;
    typedef cURLpp::OptionTrait< long, CURLOPT_RESUME_FROM > ResumeFrom;
    typedef cURLpp::OptionTrait< curl_off_t, CURLOPT_RESUME_FROM_LARGE > ResumeFromLarge;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_CUSTOMREQUEST > CustomRequest;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FILETIME > FileTime;
    typedef cURLpp::OptionTrait< bool, CURLOPT_NOBODY > NoBody;
    typedef cURLpp::OptionTrait< long, CURLOPT_INFILESIZE > InfileSize;
    typedef cURLpp::OptionTrait< curl_off_t, CURLOPT_INFILESIZE_LARGE > InfileSizeLarge;
    typedef cURLpp::OptionTrait< long, CURLOPT_MAXFILESIZE > MaxFileSize;
    typedef cURLpp::OptionTrait< curl_off_t, CURLOPT_MAXFILESIZE_LARGE > MaxFileSizeLarge;
    typedef cURLpp::OptionTrait< bool, CURLOPT_TIMECONDITION > TimeCondition;
    typedef cURLpp::OptionTrait< long, CURLOPT_TIMEVALUE > TimeValue;

    /**
     * Connection options.
     */
    typedef cURLpp::OptionTrait< long, CURLOPT_TIMEOUT > Timeout;
    typedef cURLpp::OptionTrait< long, CURLOPT_LOW_SPEED_LIMIT > LowSpeedLimit;
    typedef cURLpp::OptionTrait< long, CURLOPT_LOW_SPEED_TIME > LowSpeedTime;
    typedef cURLpp::OptionTrait< long, CURLOPT_MAXCONNECTS > MaxConnects;
    typedef cURLpp::OptionTrait< curl_closepolicy, CURLOPT_CLOSEPOLICY > ClosePolicy;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FRESH_CONNECT > FreshConnect;
    typedef cURLpp::OptionTrait< bool, CURLOPT_FORBID_REUSE > ForbidReuse;
    typedef cURLpp::OptionTrait< long, CURLOPT_CONNECTTIMEOUT > ConnectTimeout;
    typedef cURLpp::OptionTrait< long, CURLOPT_IPRESOLVE > IpResolve;
      
    /**
     * SSL and security options.
     */
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLCERT > SslCert;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLCERTTYPE > SslCertType;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLCERTPASSWD > SslCertPasswd;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLKEY > SslKey;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLKEYTYPE > SslKeyType;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLKEYPASSWD > SslKeyPasswd;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSLENGINE > SslEngine;
    typedef cURLpp::NoValueOptionTrait< CURLOPT_SSLENGINE_DEFAULT > SslEngineDefault;
    typedef cURLpp::OptionTrait< long, CURLOPT_SSLVERSION > SslVersion;
    typedef cURLpp::OptionTrait< bool, CURLOPT_SSL_VERIFYPEER > SslVerifyPeer;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_CAINFO > CaInfo;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_CAPATH > CaPath;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_RANDOM_FILE > RandomFile;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_EGDSOCKET > EgdSocket;
    typedef cURLpp::OptionTrait< long, CURLOPT_SSL_VERIFYHOST > SslVerifyHost;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_SSL_CIPHER_LIST > SslCipherList;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_KRB4LEVEL > Krb4Level;

    /**
     * Others options.
     */
    typedef cURLpp::OptionTrait< void*, CURLOPT_PRIVATE > Private;
    typedef cURLpp::OptionTrait< std::string, CURLOPT_KRB4LEVEL > Krb4Level;
    //Share;
    //TelnetOptions
  }
}

std::ostream & operator<<(std::ostream & stream, const cURLpp::Options::Url & url);

