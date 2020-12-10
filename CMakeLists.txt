cmake_minimum_required(VERSION 3.17)
project(smart_pointer_benchmark)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(smart_pointer_benchmark
               Dummy.cpp
               Dummy.h
               main.cpp
               timer.h)
