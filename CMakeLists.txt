cmake_minimum_required(VERSION 3.9)
project(cpp_test)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")

option(ENABLE_DOC "Generates the documentation target" OFF)
option(ENABLE_COVERAGE "Generates the coverage build" OFF)
option(ENABLE_TESTING "Turns on testing" OFF)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

# Enable code testing with -DENABLE_TESTING=1
if (ENABLE_TESTING OR ENABLE_COVERAGE)
    enable_testing()
    add_subdirectory(test)
endif()

# Enable code coverage with -DENABLE_COVERAGE
if (ENABLE_COVERAGE)
    set(CMAKE_BUILD_TYPE "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_NAME}_test coverage)
endif()

# Enable documentation with -DENABLE_DOC=1
if (ENABLE_DOC)
    add_subdirectory(doc)
endif()

add_subdirectory(src)