
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### install files ###############

install(FILES  EmptyType.hpp  	Functors.hpp  	NonCopyable.hpp  	NullType.hpp  	Singleton.hpp  	SmartPtr.hpp  	ThreadingFactoryMutex.hpp ThreadingFactoryMutex.inl  	ThreadingSingle.hpp ThreadingSingle.inl  	TypeList.hpp  	TypeTrait.hpp  	clone_ptr.hpp DESTINATION /include/utilspp)



#original Makefile.am contents follow:

#pkginclude_HEADERS = \
#	EmptyType.hpp \
#	Functors.hpp \
#	NonCopyable.hpp \
#	NullType.hpp \
#	Singleton.hpp \
#	SmartPtr.hpp \
#	ThreadingFactoryMutex.hpp ThreadingFactoryMutex.inl \
#	ThreadingSingle.hpp ThreadingSingle.inl \
#	TypeList.hpp \
#	TypeTrait.hpp \
#	clone_ptr.hpp
#
#pkgincludedir=$(includedir)/utilspp
