cmake_minimum_required(VERSION 3.14)

project(DBManager
        VERSION 1.0
        DESCRIPTION "Show and delete tables"
        LANGUAGES CXX 
       )

include_directories(include /usr/include/postgresql)

aux_source_directory(src ALL_SOURCES)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PostgreSQL REQUIRED)

add_executable(DBManager main.cpp ${ALL_SOURCES})
target_link_libraries(DBManager PRIVATE PostgreSQL::PostgreSQL)