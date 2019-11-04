cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

add_subdirectory(Core)
include_directories(
        Code/include
)
add_executable(budget-insight
        main.cpp
        RandomHelper.cpp
        RandomHelper.h
        TransactionTestGenerator.cpp
        TransactionTestGenerator.h
        )
target_link_libraries(budget-insight
        Catch2::Catch2
        SQLiteCpp
        sqlite3
        pthread
        dl
        budget-insight-core)
