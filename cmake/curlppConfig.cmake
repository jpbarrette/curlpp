include(CMakeFindDependencyMacro)
find_dependency(CURL)

include(${CMAKE_CURRENT_LIST_DIR}/curlppTargets.cmake)