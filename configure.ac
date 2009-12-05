AC_INIT(src/curlpp/cURLpp.cpp)
dnl AC_CONFIG_AUX_DIR(config)
AM_CONFIG_HEADER(include/curlpp/config.h)
AC_PREREQ(2.59)

dnl
dnl figure out the libcurl version
VERSION=`sed -ne 's/^#define LIBCURLPP_VERSION "\(.*\)"/\1/p' ${srcdir}/include/curlpp/cURLpp.hpp`
AM_INIT_AUTOMAKE(curlpp,$VERSION)
AC_SUBST(VERSION)

RPM_VERSION=$VERSION
AC_SUBST(RPM_VERSION)

LIBS="$LIBS -lstdc++"
dnl
dnl we extract the numerical version for curl-config only
VERSIONNUM=`sed -ne 's/^#define LIBCURLPP_VERSION_NUM 0x\(\\d\)/\1/p' ${srcdir}/include/curlpp/cURLpp.hpp`
AC_SUBST(VERSIONNUM)

dnl
dnl Solaris pkgadd support definitions
PKGADD_PKG="cURLpp"
PKGADD_NAME="cURLpp - a client that groks URLs++"
PKGADD_VENDOR="http://rrette.com/curlpp.html"
AC_SUBST(PKGADD_PKG)
AC_SUBST(PKGADD_NAME)
AC_SUBST(PKGADD_VENDOR)

AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_LANG_CPLUSPLUS       

AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
dnl BOOST_REQUIRE
AX_BOOST_BASE([1.33.1])
AM_CONDITIONAL(HAVE_BOOST, test x$want_boost = xyes)

dnl AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

LIBTOOL="$LIBTOOL --silent"

CXXFLAGS="`echo $CXXFLAGS | sed -e 's/-O[[0-9]]*//'`"
CURLPP_CXXFLAGS=""

case $host in
  *-*-cygwin | *-*-mingw* | *-*-pw32*)
    need_no_undefined=yes
    ;;
  *)
    need_no_undefined=no
    ;;
esac

AM_CONDITIONAL(NO_UNDEFINED, test x$need_no_undefined = xyes)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS( \
curl/curl.h \
ostream 
)
if test $ac_cv_header_curl_curl_h = no; then
   AC_MSG_ERROR([*** curl/curl.h. You need a working libcurl installation.])
fi


dnl -------
dnl set my_cv_curl_vers to the version of libcurl or NONE
dnl if libcurl is not found or is too old
 
AC_DEFUN([MY_CURL],[
 AC_CACHE_VAL(my_cv_curl_vers,[
 my_cv_curl_vers=NONE
 dnl check is the plain-text version of the required version
 check="7.10.0"
 dnl check_hex must be UPPERCASE if any hex letters are present
 check_hex="070A00"
 
 AC_MSG_CHECKING([for curl >= $check])
 
 if eval curl-config --version 2>/dev/null >/dev/null; then
   ver=`curl-config --version | sed -e "s/libcurl //g"`
   hex_ver=`curl-config --vernum | tr 'a-f' 'A-F'`
   ok=`echo "ibase=16; if($hex_ver>=$check_hex) $hex_ver else 0" | bc`
 
   if test x$ok != x0; then
     my_cv_curl_vers="$ver"
     AC_MSG_RESULT([$my_cv_curl_vers])
     CURL_LIBS=`curl-config --libs`
     CURL_CFLAGS=`curl-config --cflags`
     CURLPP_CXXFLAGS="$CURLPP_CXXFLAGS $CURL_CFLAGS"
     LIBS="$LIBS $CURL_LIBS"
   else
     AC_MSG_RESULT(FAILED)
     AC_MSG_WARN([$ver is too old. Need version $check or higher.])
   fi
 else
   AC_MSG_RESULT(FAILED)
   AC_MSG_WARN([curl-config was not found])
 fi
 ])
])


MY_CURL


AC_MSG_CHECKING([enable gcc warnings])
AC_ARG_ENABLE(warnings,
[  --enable-warnings       Enable warnings on compilation [default=yes]],
[ 
AC_MSG_RESULT(no)
],
[
AC_MSG_RESULT(yes)
CXXFLAGS="$CXXFLAGS -W -Wall"
]
)


AC_MSG_CHECKING([warning make an error on compilation])
AC_ARG_ENABLE(ewarning,
[  --enable-ewarning       Enable error on compilation warning [default=yes]],
[ 
AC_MSG_RESULT(no)
],
[
AC_MSG_RESULT(yes)
CXXFLAGS="$CXXFLAGS -Werror "
]
)



AC_MSG_CHECKING([whether to enable the maintener code])
AC_ARG_ENABLE(maintener,
[  --enable-maintener      Enable maintener code [default=no]],
[
CXXFLAGS="$CXXFLAGS -DENABLE_MAINTENER"
AC_MSG_RESULT(yes)
maintener="yes"
],
[
AC_MSG_RESULT(no)
maintener="no"
]
)
AM_CONDITIONAL(MAINTENER_CODE, test x$maintener = xyes)


AC_MSG_CHECKING([whether to enable Debug symbols support options])
AC_ARG_ENABLE(debug,
[  --enable-debug          Enable Debug symbols support [default=no]],
[ 
AC_MSG_RESULT(yes)
CXXFLAGS="$CXXFLAGS -ggdb3 -DCURLPP_DEBUG"
],
[
AC_MSG_RESULT(no)
]
)

AC_MSG_CHECKING([if we need BUILDING_CURLPP])
case $host in
  *-*-mingw*)
    AC_DEFINE(BUILDING_CURLPP, 1, [when building cURLpp itself])
    AC_MSG_RESULT(yes)
    AC_MSG_CHECKING([if we need CURLPP_STATICLIB])
    if test "X$enable_shared" = "Xno"
    then
      AC_DEFINE(CURLPP_STATICLIB, 1, [when not building a shared library])
      AC_MSG_RESULT(yes)
    else
      AC_MSG_RESULT(no)
    fi
    ;;
  *)
    AC_MSG_RESULT(no)
    ;;
esac

CURLPP_CXXFLAGS="$CURLPP_CXXFLAGS $BOOST_CPPFLAGS"
AC_SUBST(CURLPP_CXXFLAGS)
CXXFLAGS="$CXXFLAGS $CURLPP_CXXFLAGS"

dnl AC_CONFIG_FILES(
AC_OUTPUT(
curlpp-config \
curlpp.spec \
curlpp.pc \
Makefile \
examples/Makefile \
src/Makefile \
src/curlpp/Makefile \
src/curlpp/internal/Makefile \
src/utilspp/Makefile \
include/Makefile \
include/curlpp/Makefile \
include/curlpp/internal/Makefile \
include/utilspp/Makefile \
include/utilspp/functor/Makefile \
include/utilspp/singleton/Makefile \
doc/Makefile 
)
