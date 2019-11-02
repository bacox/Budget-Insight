cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)


add_executable(budget-insight main.cpp)