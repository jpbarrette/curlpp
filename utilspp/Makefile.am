SUBDIRS = functor singleton

noinst_LTLIBRARIES = libutilspp.la

libutilspp_la_SOURCES = \
	clone_ptr.hpp \
	EmptyType.hpp \
	Functors.hpp \
	NonCopyable.hpp \
	NullType.hpp \
	Singleton.hpp \
	SmartPtr.hpp \
	ThreadingFactoryMutex.hpp ThreadingFactoryMutex.inl \
	ThreadingSingle.hpp ThreadingSingle.inl \
	TypeList.hpp \
	TypeTrait.hpp

libutilspp_la_LIBADD = ./singleton/libsingleton.la

pkginclude_HEADERS = \
	clone_ptr.hpp \
	EmptyType.hpp \
	Functors.hpp \
	NonCopyable.hpp \
	NullType.hpp \
	Singleton.hpp \
	SmartPtr.hpp \
	ThreadingFactoryMutex.hpp ThreadingFactoryMutex.inl \
	ThreadingSingle.hpp ThreadingSingle.inl \
	TypeList.hpp \
	TypeTrait.hpp

pkgincludedir=$(includedir)/utilspp/
