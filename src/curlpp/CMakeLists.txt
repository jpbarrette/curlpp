cmake_minimum_required(VERSION 3.28)

add_library(curlpp_module)

target_sources(curlpp_module
    PUBLIC
        FILE_SET CXX_MODULES FILES
            cURLpp.cppm
)

target_compile_features(curlpp_module PUBLIC cxx_std_20)

target_include_directories(curlpp_module PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(curlpp::module ALIAS curlpp_module)

# Installation
install(TARGETS curlpp_module
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    FILE_SET CXX_MODULES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/src/curlpp
)
