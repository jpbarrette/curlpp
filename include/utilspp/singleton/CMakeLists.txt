
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### install files ###############

install(FILES  CreationStatic.hpp CreationStatic.inl  	CreationUsingNew.hpp CreationUsingNew.inl  	LifetimeDefault.hpp LifetimeDefault.inl  	LifetimeLibrary.hpp LifetimeLibrary.inl  	LifetimeWithLongevity.hpp LifetimeWithLongevity.inl  	PrivateMembers.hpp PrivateMembers.inl  	SingletonHolder.hpp SingletonHolder.inl  DESTINATION /include/utilspp/singleton)



#original Makefile.am contents follow:

#pkginclude_HEADERS = \
#	CreationStatic.hpp CreationStatic.inl \
#	CreationUsingNew.hpp CreationUsingNew.inl \
#	LifetimeDefault.hpp LifetimeDefault.inl \
#	LifetimeLibrary.hpp LifetimeLibrary.inl \
#	LifetimeWithLongevity.hpp LifetimeWithLongevity.inl \
#	PrivateMembers.hpp PrivateMembers.inl \
#	SingletonHolder.hpp SingletonHolder.inl 
#
#pkgincludedir=$(includedir)/utilspp/singleton
#
#
