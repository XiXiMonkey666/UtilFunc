# cmake_minimum_required(VERSION <specify CMake version here>)
project(UtilFunc)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)

#include_directories(/opt/third_party/x86_64/poco/include)
include_directories(util/json)
include_directories(include)
include_directories(test/include)

#link_directories(/opt/third_party/x86_64/lib#

file(GLOB CORE_SRC_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/util/*.*
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/test/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${CORE_SRC_LIST})