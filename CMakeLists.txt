project(SearchYa CXX)
cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_COLOR_MAKEFILE ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "Default build type 'Debug'")
    set(CMAKE_BUILD_TYPE DEBUG CACHE STRING "" FORCE )
else()
    string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
    message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${EXTERNAL_PROJECT_DIR})

find_package(Redis REQUIRED)
find_package(HIRedis REQUIRED)
find_package(SpdLog REQUIRED)
find_package(ProtoBuf REQUIRED)
include(installThirdParty)
