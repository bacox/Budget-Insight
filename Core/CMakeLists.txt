cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight-core)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)
include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp/include
)


# Add a library with the above sources
# add library
add_library(budget-insight-core SHARED
        src/Database.cpp
        src/Transaction.cpp
        src/Importer.cpp include/Importer.h src/TransactionApi.cpp include/TransactionApi.h)

# include the local include directory for this target only
target_include_directories(budget-insight-core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(budget-insight-core
        Catch2::Catch2
        SQLiteCpp
        sqlite3
        pthread
        dl)
