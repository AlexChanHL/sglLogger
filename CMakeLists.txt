
cmake_minimum_required(VERSION 3.27.7)
project(sglLogger VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TEST_APP)
message("test app")
endif()
if(LOGGER_MULTI)
message("multi set")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/lib)

include(CMake/ProjectSettings.cmake)


set(BUILD_TEST_APP True)

add_library(ProjectWarnings INTERFACE)
include(CMake/ProjectWarnings.cmake)
set_project_warnings(ProjectWarnings)

# endif()

add_subdirectory(src)

