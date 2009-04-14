
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### install files ###############

install(FILES  Binder.hpp   	FunctorHandler.hpp  	Functor.hpp  	FunctorImpl.hpp  	MemFunHandler.hpp DESTINATION /include/utilspp/functor)



#original Makefile.am contents follow:

#pkginclude_HEADERS = \
#	Binder.hpp  \
#	FunctorHandler.hpp \
#	Functor.hpp \
#	FunctorImpl.hpp \
#	MemFunHandler.hpp
#
#pkgincludedir=$(includedir)/utilspp/functor
