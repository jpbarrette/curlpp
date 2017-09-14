#.rst:
# FindCURLpp
# --------
#
# Find cURLpp
#
# Find the native cURLpp headers and libraries.
#
# ::
#
#   CURLPP_INCLUDE_DIRS   - where to find curl/curl.h, etc.
#   CURLPP_LIBRARIES      - List of libraries when using curl.
#   CURLPP_FOUND          - True if curl found.
#   CURLPP_VERSION_STRING - the version of curl found (since CMake 2.8.8)


find_package(PkgConfig)
pkg_check_modules(PC_CURLPP QUIET curlpp)

# Look for the header file.
find_path(CURLPP_INCLUDE_DIR
  NAMES curlpp/cURLpp.hpp
  HINTS
  ${PC_CURLPP_INCLUDE_DIRS})
mark_as_advanced(CURLPP_INCLUDE_DIR)
message(STATUS "my CURLPP_INCLUDE_DIR: ${CURLPP_INCLUDE_DIR}")


# Look for the library (sorted from most current/relevant entry to least).
find_library(CURLPP_LIBRARY NAMES
  curlpp
  # Windows static prebuilts (libcurlpp.lib):
  libcurlpp
  HINTS
  ${PC_CURLPP_LIBRARY_DIRS})
mark_as_advanced(CURLPP_LIBRARY)
message(STATUS "my CURLPP_LIBRARY: ${CURLPP_LIBRARY}")

if(CURLPP_INCLUDE_DIR)
  if(EXISTS "${CURLPP_INCLUDE_DIR}/curlpp/cURLpp.hpp")
    file(STRINGS "${CURLPP_INCLUDE_DIR}/curlpp/cURLpp.hpp" curlpp_version_str REGEX "^#define[\t ]+LIBCURLPP_VERSION[\t ]+\".*\"")

    string(REGEX REPLACE "^#define[\t ]+LIBCURLPP_VERSION[\t ]+\"([^\"]*)\".*" "\\1" CURLPP_VERSION_STRING "${curlpp_version_str}")
    unset(curlpp_version_str)
  endif()
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CURLPP
                                  REQUIRED_VARS CURLPP_LIBRARY CURLPP_INCLUDE_DIR
                                  VERSION_VAR CURLPP_VERSION_STRING)

if(CURLPP_FOUND)
  set(CURLPP_LIBRARIES ${CURLPP_LIBRARY})
  set(CURLPP_INCLUDE_DIRS ${CURLPP_INCLUDE_DIR})
endif()
