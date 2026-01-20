/*
 *    Copyright (c) <2002-2026> <Jean-Philippe Barrette-LaPierre>
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

module;

#include "curlpp/cURLpp.hpp"
#include "curlpp/Easy.hpp"
#include "curlpp/Exception.hpp"
#include "curlpp/Form.hpp"
#include "curlpp/Info.hpp"
#include "curlpp/Infos.hpp"
#include "curlpp/Multi.hpp"
#include "curlpp/Option.hpp"
#include "curlpp/OptionBase.hpp"
#include "curlpp/Options.hpp"
#include "curlpp/Types.hpp"

export module curlpp;

export namespace curlpp {
    using curlpp::Cleanup;
    using curlpp::Easy;
    using curlpp::RuntimeError;
    using curlpp::LogicError;
    using curlpp::LibcurlRuntimeError;
    using curlpp::LibcurlLogicError;
    using curlpp::UnsetOption;
    using curlpp::NotAvailable;
    using curlpp::UnknowException;
    using curlpp::CallbackExceptionBase;
    using curlpp::CallbackException;
    using curlpp::FormPart;
    using curlpp::Forms;
    using curlpp::HttpPost;

    namespace FormParts {
        using curlpp::FormParts::File;
        using curlpp::FormParts::Content;
    }

    namespace formparts = FormParts;

    using curlpp::InfoType;
    using curlpp::Info;
    using curlpp::NotAvailableInfo;
    using curlpp::InfoGetter;
    using curlpp::InfoTypeConverter;

    namespace infos {
        using curlpp::infos::EffectiveUrl;
        using curlpp::infos::ResponseCode;
        using curlpp::infos::HttpConnectCode;
        using curlpp::infos::FileTime;
        using curlpp::infos::FileTimeT;
        using curlpp::infos::TotalTime;
        using curlpp::infos::NameLookupTime;
        using curlpp::infos::ConnectTime;
        using curlpp::infos::PreTransferTime;
        using curlpp::infos::StartTransferTime;
        using curlpp::infos::RedirectTime;
        using curlpp::infos::RedirectCount;
        using curlpp::infos::SizeUpload;
        using curlpp::infos::SizeUploadT;
        using curlpp::infos::SizeDownload;
        using curlpp::infos::SizeDownloadT;
        using curlpp::infos::SpeedDownload;
        using curlpp::infos::SpeedDownloadT;
        using curlpp::infos::SpeedUpload;
        using curlpp::infos::SpeedUploadT;
        using curlpp::infos::HeaderSize;
        using curlpp::infos::RequestSize;
        using curlpp::infos::SslVerifyResult;
        #if LIBCURL_VERSION_NUM >= 0x070c03
        using curlpp::infos::SslEngines;
        #endif
        using curlpp::infos::ContentLengthDownload;
        using curlpp::infos::ContentLengthDownloadT;
        using curlpp::infos::ContentLengthUpload;
        using curlpp::infos::ContentLengthUploadT;
        using curlpp::infos::ContentType;
        using curlpp::infos::HttpAuthAvail;
        using curlpp::infos::ProxyAuthAvail;
        #if LIBCURL_VERSION_NUM >= 0x070c02
        using curlpp::infos::OsErrno;
        #endif
        #if LIBCURL_VERSION_NUM >= 0x070c03
        using curlpp::infos::NumConnects;
        #endif
        #if LIBCURL_VERSION_NUM >= 0x070e01 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::infos::CookieList;
        #endif
    }

    namespace Infos = infos;

    using curlpp::Multi;
    using curlpp::Option;
    using curlpp::OptionTrait;
    using curlpp::NoValueOptionTrait;
    using curlpp::NotAvailableOptionTrait;
    using curlpp::OptionBase;

    namespace options {
        #if LIBCURL_VERSION_NUM >= 0x070d01 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::CookieList;
        #endif
        using curlpp::options::Verbose;
        using curlpp::options::Header;
        #if LIBCURL_VERSION_NUM >= 0x070A00 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::NoSignal;
        #endif
        using curlpp::options::NoProgress;
        using curlpp::options::WriteFunctionCurlFunction;
        using curlpp::options::WriteFunction;
        #if LIBCURL_VERSION_NUM >= 0x070907 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::WriteFile;
        using curlpp::options::WriteStream;
        #endif
        #if LIBCURL_VERSION_NUM >= 0x070c01 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::ReadFunctionCurlFunction;
        using curlpp::options::ReadFunction;
        #endif
        #if LIBCURL_VERSION_NUM >= 0x070907 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::ReadFile;
        using curlpp::options::ReadStream;
        #endif
        using curlpp::options::ProgressFunction;
        using curlpp::options::HeaderFunction;
        using curlpp::options::DebugFunction;
        using curlpp::options::SslCtxFunction;
        using curlpp::options::ErrorBuffer;
        #ifdef FILE
        using curlpp::options::StdErr;
        #endif
        using curlpp::options::FailOnError;
        using curlpp::options::Url;
        using curlpp::options::Proxy;
        using curlpp::options::ProxyPort;
        using curlpp::options::ProxyType;
        using curlpp::options::HttpProxyTunnel;
        using curlpp::options::Interface;
        using curlpp::options::DnsCacheTimeout;
        using curlpp::options::DnsUseGlobalCache;
        using curlpp::options::BufferSize;
        using curlpp::options::Port;
        using curlpp::options::TcpNoDelay;
        using curlpp::options::Netrc;
        using curlpp::options::NetrcFile;
        using curlpp::options::UserPwd;
        using curlpp::options::ProxyUserPwd;
        using curlpp::options::HttpAuth;
        using curlpp::options::ProxyAuth;
        using curlpp::options::AutoReferer;
        using curlpp::options::FollowLocation;
        using curlpp::options::UnrestrictedAuth;
        using curlpp::options::MaxRedirs;
        using curlpp::options::Put;
        using curlpp::options::Upload;
        using curlpp::options::Post;
        using curlpp::options::PostFields;
        using curlpp::options::PostFieldSize;
        using curlpp::options::PostFieldSizeLarge;
        using curlpp::options::HttpPost;
        using curlpp::options::Referer;
        using curlpp::options::UserAgent;
        using curlpp::options::HttpHeader;
        using curlpp::options::Http200Aliases;
        using curlpp::options::Cookie;
        using curlpp::options::CookieFile;
        using curlpp::options::CookieJar;
        using curlpp::options::HttpGet;
        using curlpp::options::HttpVersion;
        using curlpp::options::FtpPort;
        using curlpp::options::Quote;
        using curlpp::options::PostQuote;
        using curlpp::options::PreQuote;
        using curlpp::options::FtpUseEpsv;
        using curlpp::options::FtpFileMethod;
        using curlpp::options::FtpCreateMissingDirs;
        using curlpp::options::FtpSslAuth;
        using curlpp::options::MailFrom;
        using curlpp::options::MailRcpt;
        #if LIBCURL_VERSION_NUM >= 0x071900 || defined(CURLPP_ALLOW_NOT_AVAILABLE)
        using curlpp::options::MailAuth;
        #endif
        using curlpp::options::TransferText;
        using curlpp::options::Crlf;
        using curlpp::options::Range;
        using curlpp::options::ResumeFrom;
        using curlpp::options::ResumeFromLarge;
        using curlpp::options::CustomRequest;
        using curlpp::options::FileTime;
        using curlpp::options::NoBody;
        using curlpp::options::InfileSize;
        using curlpp::options::InfileSizeLarge;
        using curlpp::options::MaxFileSize;
        using curlpp::options::MaxFileSizeLarge;
        using curlpp::options::TimeCondition;
        using curlpp::options::TimeValue;
        using curlpp::options::Timeout;
        using curlpp::options::LowSpeedLimit;
        using curlpp::options::LowSpeedTime;
        using curlpp::options::MaxConnects;
        using curlpp::options::FreshConnect;
        using curlpp::options::ForbidReuse;
        using curlpp::options::ConnectTimeout;
        using curlpp::options::IpResolve;
        using curlpp::options::UseSsl;
        using curlpp::options::SslOptions;
        using curlpp::options::SslCert;
        using curlpp::options::SslCertType;
        using curlpp::options::SslKey;
        using curlpp::options::SslKeyType;
        using curlpp::options::SslEngine;
        using curlpp::options::SslEngineDefault;
        using curlpp::options::SslVersion;
        using curlpp::options::SslVerifyPeer;
        using curlpp::options::CaInfo;
        using curlpp::options::CaPath;
        using curlpp::options::RandomFile;
        using curlpp::options::EgdSocket;
        using curlpp::options::SslVerifyHost;
        using curlpp::options::SslCipherList;
        using curlpp::options::Private;

        #ifndef CURL_NO_OLDIES
        using curlpp::options::Krb4Level;
        using curlpp::options::SslKeyPasswd;
        using curlpp::options::SslCertPasswd;
        using curlpp::options::FtpSsl;
        using curlpp::options::FtpResponseTimeout;
        using curlpp::options::FtpAppend;
        using curlpp::options::FtpListOnly;
        using curlpp::options::Encoding;
        #endif
    }

    namespace Options = options;

    namespace types {
        using curlpp::types::WriteFunctionFunctor;
        using curlpp::types::ReadFunctionFunctor;
        using curlpp::types::DebugFunctionFunctor;
        using curlpp::types::SslCtxFunctionFunctor;
        using curlpp::types::ProgressFunctionFunctor;
    }

    namespace Types = types;

    using curlpp::initialize;
    using curlpp::terminate;
    using curlpp::escape;
    using curlpp::unescape;
    using curlpp::getenv;
    using curlpp::libcurlVersion;
    using curlpp::getdate;
    using curlpp::raiseException;
    using curlpp::createCallbackException;
    using curlpp::libcurlRuntimeAssert;
    using curlpp::libcurlLogicAssert;
    using curlpp::runtimeAssert;
    using curlpp::logicAssert;

    using ::operator<<;
}

export namespace cURLpp = curlpp;
