
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### next target ###############

set(singleton_STAT_SRCS LifetimeLibrary.cpp PrivateMembers.cpp)

kde4_add_library(singleton STATIC ${singleton_STAT_SRCS})


########### install files ###############




#original Makefile.am contents follow:

#noinst_LTLIBRARIES = libsingleton.la
#
#libsingleton_la_SOURCES = \
#	LifetimeLibrary.cpp \
#	PrivateMembers.cpp
#
#INCLUDES = -I$(top_builddir)/include
#
#AM_CXXFLAGS=
#
