# extracting curlpp version text + version num
file (READ ${CURLPP_SOURCE_DIR}/include/curlpp/cURLpp.hpp CURLPP_VERSION_H_CONTENTS)

string (REGEX MATCH "#define LIBCURLPP_VERSION \"[^\"]*"
  CURLPP_VERSION ${CURLPP_VERSION_H_CONTENTS})
string (REGEX REPLACE "[^\"]+\"" "" CURLPP_VERSION ${CURLPP_VERSION})
string (REGEX MATCH "#define LIBCURLPP_VERSION_NUM 0x[0-9a-fA-F]+"
  CURLPP_VERSION_NUM ${CURLPP_VERSION_H_CONTENTS})
string (REGEX REPLACE "[^0]+0x" "" CURLPP_VERSION_NUM ${CURLPP_VERSION_NUM})

message(STATUS "curlpp version=[${CURLPP_VERSION}]")
message(STATUS "curlpp version num=[${CURLPP_VERSION_NUM}]")


# curlpp-config needs the following options to be set.
string(REPLACE "." "" libext "${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(CC "${CMAKE_C_COMPILER}")
set(libdir "${CMAKE_INSTALL_PREFIX}/lib")
set(libdir_static "${CMAKE_INSTALL_PREFIX}/lib/static")
set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "\${prefix}")
set(includedir "\${prefix}/include")

set(LDFLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

# Finally generate a "curl-config" matching this config
configure_file("${CURLPP_SOURCE_DIR}/extras/curlpp-config.in"
               "${CURLPP_BINARY_DIR}/curlpp-config" @ONLY)
install(FILES "${CURLPP_BINARY_DIR}/curlpp-config"
        DESTINATION bin
        PERMISSIONS
          OWNER_READ OWNER_WRITE OWNER_EXECUTE
          GROUP_READ GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE)




# Finally generate a pkg-config file matching this config
configure_file("${CURLPP_SOURCE_DIR}/extras/curlpp.pc.in"
               "${CURLPP_BINARY_DIR}/curlpp.pc" @ONLY)
install(FILES "${CURLPP_BINARY_DIR}/curlpp.pc"
        DESTINATION lib/pkgconfig)
