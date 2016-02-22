cmake_minimum_required(VERSION 3.3)
project(general)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

set(SOURCE_FILES main.cpp)
add_executable(general ${SOURCE_FILES})