cmake_minimum_required(VERSION 3.1)
set(cur_path ${CMAKE_SOURCE_DIR})

message(STATUS "cur_path = ${cur_path}")
project(json-project)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++0x" )
include_directories(
    ${cur_path}/include
)

file(GLOB SOURCES 
        "${cur_path}/src/*.cpp"
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(install_gtest OFF)
set(install_gmock OFF)
set(build_gmock ON)

add_subdirectory("third_party/googletest")

add_executable(json-project ${SOURCES})

TARGET_LINK_LIBRARIES(json-project gtest gtest_main pthread)
