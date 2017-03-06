cmake_minimum_required(VERSION 2.8)

# Conan.io integration
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../extras")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")


include(FindCURLpp)
find_package(CURLPP REQUIRED)


# c++11 support for cmake 2.8.12 or newer
#
# for non-windows platform we try to keep cmake 2.8 support
# since entreprise distribution tends to have 2.8 version.
add_compile_options(-std=c++11) 
include_directories(${CURLPP_INCLUDE_DIRS})

file(GLOB ExamplesFileList "*.cpp")

# Create a meta target to create examples
add_custom_target(build_all_examples COMMENT A target that requires all the examples.)

message(STATUS "Creating build rules for Examples:")
foreach(Example ${ExamplesFileList})
  message(STATUS "\tCreating build rule for ${Example}")
  # Get the name without extension or directory
  get_filename_component(ExampleName ${Example} NAME_WE)
  # Define example executable
  add_executable(${ExampleName} ${Example})
  # Link example against curlpp
  target_link_libraries(${ExampleName} ${CURLPP_LDFLAGS})
  # make the meta target depend on this example.
  add_dependencies(build_all_examples ${ExampleName})
endforeach(Example ${ExamplesFileList})
