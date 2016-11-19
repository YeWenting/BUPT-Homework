cmake_minimum_required(VERSION 3.6)
project(Producer_Comsumer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

set(SOURCE_FILES main.c)
add_executable(Producer_Comsumer ${SOURCE_FILES})