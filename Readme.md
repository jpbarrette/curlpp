---
title: cURLpp
---

# Description

cURLpp is a C++ wrapper for libcURL. libcURL is described as:

<cite>
a free and easy-to-use client-side URL transfer library, supporting FTP, FTPS, HTTP, HTTPS, GOPHER, TELNET, DICT, FILE and LDAP. libcurl supports HTTPS certificates, HTTP POST, HTTP PUT, FTP uploading, kerberos, HTTP form based upload, proxies, cookies, user+password authentication, file transfer resume, http proxy tunneling and more!
</cite>

<cite>
libcurl is highly portable, it builds and works identically on numerous platforms, including Solaris, NetBSD, FreeBSD, OpenBSD, Darwin, HPUX, IRIX, AIX, Tru64, Linux, Windows, Amiga, OS/2, BeOs, Mac OS X, Ultrix, QNX, OpenVMS, RISC OS, Novell NetWare, DOS and more...
</cite>

<cite>
libcurl is free, thread-safe, IPv6 compatible, feature rich, well supported and fast.
</cite>

First, I need to quote Daniel Stenberg, the maintener of libcURL:
<cite>You can use libcURL instantly from within your C++ programs. You don't need cURLpp for that, cURLpp just adds an OO'ified layer that libcURL doesn't normally provide.</cite> It means that you need to be sure that you need, or want, cURLpp features. If not, I suggest to use directly the libcURL library. So, what are thoses features that cURLpp offers?

* You can query handles for option values (version 0.5.x and newer only).
* It use the C++ standard library structures instead of home made ones.
* It is exception safe.
* It is type safe.

#Downloads

See cURLpp's [github](http://github.com/jpbarrette/curlpp) repo for this.

#License

<cite>
cURLpp is true Open Source/Free Software and meet all definitions as such. It means that you are free to modify and redistribute all contents of the cURLpp distributed archives. You may also freely use cURLpp in your commercial projects. cURLpp is licensed under a MIT license, see below.

<cite>Copyright @ 2002-2006, Jean-Philippe Barrette-LaPierre

<cite>Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

<cite>The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

<cite>THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
</cite> 

# Documentation

The programming guide for the 0.5.x and newer versions is [here](https://github.com/jpbarrette/curlpp/tree/master/doc/guide.pdf). This guide is greatly inspired by the libcURL guide, that I strongly suggest to read. There's also some examples in the "[examples](http://github.com/jpbarrette/curlpp/tree/master/examples)/" source directory of cURLpp.

# Development history

## The original code (versions up to 0.3x)

This project was branched over the project began by Eric Lavigne. It's no longer active.

## The refactor over the original code (0.5.x and newer)

This version is a complete re-factorization of cURLpp against 0.3.x and older versions. This re-factorization was made for the following reasons:

* cURLpp was difficult to maintain.
* cURLpp wasn't flexible.

Those two points are in fact related. cURLpp was difficult to maintain because each libcURL's option change needed a change in cURLpp; the design didn't allow those changes to be automatically taken in charge. Because I don't monitor libcURL project carefully, those changes were only applied 2-3 months after the release. It wasn't flexible because it didn't allowed the user to change cURLpp's behavior without risking to break previously made applications.

But in fact, the real problem is that I DO read feature requests, but do not necessarily program them (You can send your complains to my university/job/girlfriend). So, this design is, in fact, "Ze" one that is compatible with my laziness.

Seriously, here's the advantages of this new design:

* Allow you to change cURLpp's C++ wrapping behavior, without requiring its recompilation.
* Allow you to retrieve the option values already set on the handle.
* For more details, see the guide. Note that, as you probably deduced, this version is NOT compatible against 0.3.x and older versions.

## Development Plans

So, what's next? I have some ideas for future releases. If you want to suggest some feature, don't be shy and send me an email.

### Version 0.6.0 (Out)

Exception safe feature. What's exactly the matter? Isn't supposed to be already exception safe? Well, the problem is when you work with C++ callbacks that are called within C code. What will happen if the callback throw an exception? The exception will go through the C code. This will completely break the C code. So, you need to be sure that it's impossible that an exception is thrown, without being handled in your callback. So, I want to add some code that will handle any exception thrown and rethrow it in the C++ code, meaning in the cURLpp::Easy::perform function. Then, you'll be able to throw exceptions, without being scared to break libcURL's execution.

Functors. At this time we use plain functions as callbacks. However, if you want to use a member function, you need to create a function that will cast your data (that you previously set on the handle), and then call your member function. I want to use functors instead. If you don't know what are functors, check this.

### Version 0.7.0 (Out)

Multi interface. We need to add the Multi interface. Here's the description from libcURL's documentation: 
The multi interface is the asynchronous brother in the family and it also offers multiple transfers using a single thread and more. The multi interface introduces several new abilities that the easy interface refuses to offer. They are mainly:

* Enable a "pull" interface. The application that uses libcurl decides where and when to ask libcurl to get/send data.
* Enable multiple simultaneous transfers in the same thread without making it complicated for the application.
* Enable the application to select() on its own file descriptors and curl's file descriptors simultaneous easily.

### Version 0.8.0

Share interface. Right now, we don't provide any wrapping for the Share interface. Mostly, this wrapping will depend on the functor feature. This is the description from the libcURL documentation: The share interface was added to enable sharing of data between curl "handles". You can have multiple easy handles share data between them. Have them update and use the same cookie database or DNS cache! This way, each single transfer will take advantage from data updates made by the other transfer(s).

# Compilers

cURLpp is meant to be portable, but I can't maintain, all by myself, a project file for every platform that exists. Here's the environnements that I maintain, or will maintain personally:

* Max OS X/GCC 2.95/GCC 3.x/GCC 4.x
* Linux/GCC 2.95/GCC 3.x/GCC 4.x
* Cygwin/GCC 2.95/GCC 3.x/GCC 4.x
* I know there's some people who wants a VC++ project file. I don't want to maintain those VC++ files. I don't want to because I don't have any licence of VC++ and I don't want to buy one. The only way I will make available some Win32 binaries(DLL), is with MinGW. However, if someone is willing to maintain thoses files, it will be my pleasure to make them available.

# Mailing-List

If you have some questions or bugs to submit, you call send an email to the mailing-list. You need to register to the mailing-list before sending any email. However, keep in mind that cURLpp is a C++ wrapper over libcURL, so if you have a libcURL feature's related question, send it to libcURL's mailing-list.

