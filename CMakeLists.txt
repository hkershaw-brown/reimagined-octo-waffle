cmake_minimum_required(VERSION 3.10)

project(CppGameProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(CppGameProject ${SOURCES})