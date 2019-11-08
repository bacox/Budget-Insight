cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight-server)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

add_subdirectory(thirdparty/jsoncpp)
include_directories(thirdparty/jsoncpp/include)
add_subdirectory(thirdparty/mongoose-cpp)
include_directories(thirdparty/mongoose-cpp)

# Add a library with the above sources
# add library
add_library(budget-insight-server SHARED
        src/ApiHandler.cpp
        src/WebServer.cpp include/WebServer.h)

# include the local include directory for this target only
target_include_directories(budget-insight-server PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
set_property(TARGET mongoose PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(budget-insight-server
        Catch2::Catch2
        SQLiteCpp
        sqlite3
        pthread
        dl
        budget-insight-core
        jsoncpp_lib
        mongoose)
