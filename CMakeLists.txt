cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project (budget-insight)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
find_package(Catch2 REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/bin)


add_subdirectory(thirdparty/spdlog)
#find_package(spdlog)
include_directories(
        thirdparty/spdlog/include
)

SET(WEBSERVER ${CMAKE_BINARY_DIR}/target/www)
SET(WEBSERVER_BARE ${CMAKE_BINARY_DIR}/target)

MESSAGE(STATUS "Copying www files")
IF (WIN32)
    MESSAGE(STATUS "Copting www files instead of symlink because of windows")
    file(MAKE_DIRECTORY ${WEBSERVER})
    fille(GLOB_RECURSE webFiles "www/*.*")
    foreach(webFile ${webFiles})
        file(RELATIVE_PATH relativeWebFile "${CMAKE_SOURCE_DIR}/www" "${webFile}")
        MESSAGE(STATUS "The files in the www folder: ${relativeWebFile}")
        configure_file(www/${relativeWebFile} ${WEBSERVER}/${relativeWebFile} COPYONLY)
    endforeach()
ELSE()
    MESSAGE(STATUS "Using symlink for the www files")
    file(MAKE_DIRECTORY ${WEBSERVER_BARE})
    execute_process(COMMAND  bash -c "ln -s ${CMAKE_SOURCE_DIR}/www ${WEBSERVER_BARE}")
ENDIF()



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

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
    message(STATUS "dir='${dir}'")
endforeach()

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
