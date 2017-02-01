project(curlpp) 

if(WIN32)
    # cmake 3.4 is required for CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
    cmake_minimum_required(VERSION 3.4)
else()
    cmake_minimum_required(VERSION 3.0)
endif()

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CURLPP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CURLPP_BINARY_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


#########################################################################################
# Root folders
set(ProjectRootDir ${${PROJECT_NAME}_SOURCE_DIR}/)
message(STATUS "\tUsing Sources From: ${ProjectRootDir}")

set(ProjectBinaryDir ${${PROJECT_NAME}_BINARY_DIR}/)
message(STATUS "\tPutting all major output in: ${ProjectBinaryDir}")

# Source Subfolders
set(SrcFolder ${ProjectRootDir}src/)
message(STATUS "\tInputs of type .cpp at: ${SrcFolder}")

set(IncludeFolder ${ProjectRootDir}include/)
message(STATUS "\tInputs of type .h and .hpp at: ${IncludeFolder}")

set(ExamplesFolder ${ProjectRootDir}examples/)
message(STATUS "\tInputs to be built as standalone examples are at: ${ExamplesFolder}")

add_subdirectory(extras)

#########################################################################################
# For more verbose displays
function(DisplayList Header ListToShow)
    message(STATUS "\t${Header}")
    foreach(ListItem ${ListToShow})
        message(STATUS "\t\t${ListItem}")
    endforeach(ListItem ${ListToShow})
endfunction(DisplayList)

#########################################################################################
# File Lists
file(GLOB_RECURSE HeaderFileList "${IncludeFolder}*")
install(DIRECTORY include/utilspp/ DESTINATION "include/utilspp")
install(DIRECTORY include/curlpp/ DESTINATION "include/curlpp")
DisplayList("Using Header Files:" "${HeaderFileList}")

file(GLOB_RECURSE SourceFileList "${SrcFolder}*")
DisplayList("Using Source Files:" "${SourceFileList}")

#########################################################################################
# Look for dependencies

# Documented at https://cmake.org/cmake/help/v3.0/module/FindCURL.html?highlight=curlpp
# Seems simple.

message(STATUS "Looking for CURL")
include(FindCURL)
cmake_minimum_required(VERSION 3.0)
find_package(CURL REQUIRED)

if(${CURL_FOUND})
  message(STATUS "Found CURL version: ${CURL_VERSION_STRING}")
  message(STATUS "Using CURL include dir(s): ${CURL_INCLUDE_DIRS}")
  message(STATUS "Using CURL lib(s): ${CURL_LIBRARIES}")
else(${CURL_FOUND})
  message(FATAL_ERROR "Could not find CURL")
endif(${CURL_FOUND})

# All following targets should search these directories for headers
include_directories( 
  ${IncludeFolder}
  ${CURL_INCLUDE_DIRS}
)

#########################################################################################
# Connect all the found parts

# Define main library
message(STATUS 
  "Defining the shared library for ${PROJECT_NAME} including "
  "all source and header files not in examples."
)

add_library(${PROJECT_NAME} SHARED ${HeaderFileList} ${SourceFileList})
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})

add_library(${PROJECT_NAME}_static STATIC ${HeaderFileList} ${SourceFileList})
target_link_libraries(${PROJECT_NAME}_static ${CURL_LIBRARIES})

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

