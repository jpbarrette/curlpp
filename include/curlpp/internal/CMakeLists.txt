
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### install files ###############

install(FILES  CurlHandle.hpp CurlHandle.inl  	OptionContainer.hpp OptionContainer.inl	OptionContainerType.hpp  	OptionList.hpp  	OptionSetter.hpp OptionSetter.inl  	SList.hpp  	buildconfig.h  	DESTINATION /include/curlpp/internal)



#original Makefile.am contents follow:

#pkginclude_HEADERS = \
#	CurlHandle.hpp CurlHandle.inl \
#	OptionContainer.hpp OptionContainer.inl	OptionContainerType.hpp \
#	OptionList.hpp \
#	OptionSetter.hpp OptionSetter.inl \
#	SList.hpp \
#	buildconfig.h
#
#pkgincludedir=$(includedir)/curlpp/internal
