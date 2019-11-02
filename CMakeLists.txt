cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)
add_executable(budget-insight main.cpp Transaction.cpp Transaction.h RandomHelper.cpp RandomHelper.h)
target_link_libraries(budget-insight Catch2::Catch2)
