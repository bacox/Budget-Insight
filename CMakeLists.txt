cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/bin)

add_subdirectory(thirdparty/spdlog)
include_directories(
        thirdparty/spdlog/include
)

SET(WEBSERVER ${CMAKE_BINARY_DIR}/target/www)
file(MAKE_DIRECTORY ${WEBSERVER})
configure_file(www/index.html ${WEBSERVER}/index.html COPYONLY)
configure_file(www/all-transactions.html ${WEBSERVER}/all-transactions.html COPYONLY)
configure_file(www/by-id.html ${WEBSERVER}/by-id.html COPYONLY)
configure_file(www/data.csv ${WEBSERVER}/data.csv COPYONLY)

add_subdirectory(Core)
include_directories(
        Code/include
)
add_subdirectory(Server)
include_directories(
        Server/include
        Server/thirdparty/mongoose-cpp
        Server/thirdparty/jsoncpp/include
)
#include_directories(Server/thirdparty/mongoose-cpp)

add_executable(budget-insight
        Util/src/RandomHelper.cpp
        Util/src/TransactionTestGenerator.cpp
        Util/include/RandomHelper.h
        Util/include/TransactionTestGenerator.h
        main.cpp
        Util/src/Log.cpp
        Util/include/Log.h)

target_link_libraries(budget-insight
        Catch2::Catch2
        pthread
        dl
        budget-insight-core
        budget-insight-server
        spdlog
        )
