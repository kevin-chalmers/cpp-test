cmake_minimum_required(VERSION 3.9)
project(cpp_test)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")

option(ENABLE_DOC "Generates the documentation target" OFF)
option(ENABLE_COVERAGE "Generates the coverage build" OFF)
option(ENABLE_TESTING "Turns on testing" ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(include)

add_library(coverage_config INTERFACE)

# Enable code testing with -DENABLE_TESTING=1
if ((ENABLE_TESTING OR ENABLE_COVERAGE) AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    enable_testing()
    target_compile_options(coverage_config INTERFACE
        -O0
        -g
        --coverage
    )
    if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif()
    # Prevent overriding the parent project's compiler/linker
    # settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(extern/googletest)
    include_directories(extern/googletest/googletest/include extern/googletest/googlemock/include)
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

link_libraries(coverage_config)

add_subdirectory(src)