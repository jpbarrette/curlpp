
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

add_subdirectory(singleton)


########### next target ###############

set(utilspp_STAT_SRCS
    clone_ptr.hpp
    EmptyType.hpp
    Functors.hpp
    NonCopyable.hpp
    NullType.hpp
    Singleton.hpp
    SmartPtr.hpp
    ThreadingFactoryMutex.hpp
    ThreadingFactoryMutex.inl
    ThreadingSingle.hpp
    ThreadingSingle.inl
    TypeList.hpp
    TypeTrait.hpp)

add_library(utilspp STATIC ${utilspp_STAT_SRCS})


########### install files ###############




#original Makefile.am contents follow:

#SUBDIRS = singleton
#
#noinst_LTLIBRARIES = libutilspp.la
#
#libutilspp_la_SOURCES = \
#	clone_ptr.hpp \
#	EmptyType.hpp \
#	Functors.hpp \
#	NonCopyable.hpp \
#	NullType.hpp \
#	Singleton.hpp \
#	SmartPtr.hpp \
#	ThreadingFactoryMutex.hpp ThreadingFactoryMutex.inl \
#	ThreadingSingle.hpp ThreadingSingle.inl \
#	TypeList.hpp \
#	TypeTrait.hpp
#
#libutilspp_la_LIBADD = ./singleton/libsingleton.la
#
