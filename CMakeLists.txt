
#find_package(boost REQUIRED)

#include(MacroLibrary)

#include(ConvenienceLibs.cmake)

#include(ManualStuff.cmake)

#include(ConfigureChecks.cmake)

#include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(examples)
add_subdirectory(doc)


########### install files ###############

install(FILES  curlpp-config DESTINATION )
install(FILES  curlpp.pc DESTINATION )


#original Makefile.am contents follow:

#ACLOCAL_AMFLAGS = -I m4
#SUBDIRS = src include examples doc 
#EXTRA_DIST = curlpp.vcproj curlpp.sln CHANGES curlpp.spec
#
#pkgconfigdir = $(libdir)/pkgconfig
#pkgconfig_DATA = curlpp.pc
#
#bin_SCRIPTS = curlpp-config
#
