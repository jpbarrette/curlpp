noinst_LTLIBRARIES = libinternal.la

if MAINTENER_CODE
maintener_source = 
endif

INCLUDES = -I$(top_builddir)/include/curlpp -I$(top_builddir)/include/curlpp/internal -I$(top_builddir)/include

sources = \
	CurlHandle.cpp \
	OptionList.cpp \
	OptionSetter.cpp \
	SList.cpp \
	${maintener_source}


libinternal_la_SOURCES = ${sources}

VERSION=-version-info 0:2:0

AM_CXXFLAGS= -I../ 

if NO_UNDEFINED
# The -no-undefined flag is CRUCIAL for this to build fine on Cygwin. If we
# find a case in which we need to remove this flag, we should most likely
# write a configure check that detects when this flag is needed and when its
# not.
libinternal_la_LDFLAGS = -no-undefined -Wno-inline-dllimport $(VERSION) 
else
libinternal_la_LDFLAGS = $(VERSION)
endif


