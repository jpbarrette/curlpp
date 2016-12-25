
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)


########### install files ###############

install(FILES  Easy.hpp Easy.inl  	Exception.hpp  	Form.hpp  	Info.hpp Info.inl  	Infos.hpp  	Multi.hpp  	Option.hpp Option.inl  	OptionBase.hpp  	Options.hpp  	Types.hpp  	cURLpp.hpp	DESTINATION /include/curlpp)



