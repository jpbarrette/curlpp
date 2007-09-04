lib_LTLIBRARIES = libcurlpp.la
EXTRA_DIST = Makefile.msvc

if MAINTENER_CODE
maintener_source = 
maintener_header = 
endif

sources = \
	CurlHandle.cpp CurlHandle.hpp CurlHandle.inl \
	cURLpp.cpp cURLpp.hpp \
	Exception.cpp Exception.hpp \
	Easy.cpp Easy.hpp Easy.inl \
	Form.cpp Form.hpp \
	Info.cpp Info.hpp Info.inl \
	Infos.hpp \
	Multi.cpp Multi.hpp \
	NonCopyable.hpp \
	OptionBase.cpp OptionBase.hpp \
	OptionContainer.hpp OptionContainer.inl \
	OptionContainerType.hpp \
	OptionList.cpp OptionList.hpp \
	OptionSetter.cpp OptionSetter.hpp OptionSetter.inl \
	Option.hpp Option.inl \
	Options.hpp \
	SList.cpp SList.hpp \
	StorageOptions.hpp StorageOptions.inl \
	Types.hpp \
	TypeTrait.hpp \
	autolink.h \
	config.h \
	config.win32.h \
	global.h \
	${maintener_source}


libcurlpp_la_SOURCES = ${sources}

pkginclude_HEADERS = \
	CurlHandle.hpp CurlHandle.inl \
	cURLpp.hpp \
	dllfct.h \
	Exception.hpp \
	Easy.hpp Easy.inl \
	Form.hpp \
	Info.hpp Info.inl \
	Infos.hpp \
	Multi.hpp \
	NonCopyable.hpp \
	OptionBase.hpp \
	OptionContainer.hpp OptionContainer.inl \
	OptionContainerType.hpp \
	OptionList.hpp \
	OptionSetter.hpp OptionSetter.inl \
	Option.hpp Option.inl \
	Options.hpp \
	SList.hpp \
	StorageOptions.hpp StorageOptions.inl \
	TypeTrait.hpp \
	Types.hpp \
	global.h \
	${maintener_header}


VERSION=-version-info 0:2:0


AM_CXXFLAGS= -I../ 
pkgincludedir=$(includedir)/curlpp


# This flag accepts an argument of the form current[:revision[:age]]. So,
# passing -version-info 3:12:1 sets current to 3, revision to 12, and age to
# 1.
#
# If either revision or age are omitted, they default to 0. Also note that age
# must be less than or equal to the current interface number.
## Here are a set of rules to help you update your library version information: 
#
# 1.Start with version information of 0:0:0 for each libtool library.
#
# 2.Update the version information only immediately before a public release of
# your software. More frequent updates are unnecessary, and only guarantee
# that the current interface number gets larger faster.
#
# 3.If the library source code has changed at all since the last update, then
# increment revision (c:r:a becomes c:r+1:a).
#
# 4.If any interfaces have been added, removed, or changed since the last
# update, increment current, and set revision to 0.
#
# 5.If any interfaces have been added since the last public release, then
# increment age.
#
# 6.If any interfaces have been removed since the last public release, then
# set age to 0.
#

if NO_UNDEFINED
# The -no-undefined flag is CRUCIAL for this to build fine on Cygwin. If we
# find a case in which we need to remove this flag, we should most likely
# write a configure check that detects when this flag is needed and when its
# not.
libcurlpp_la_LDFLAGS = -no-undefined -Wno-inline-dllimport $(VERSION)
else
libcurlpp_la_LDFLAGS = $(VERSION)
endif
