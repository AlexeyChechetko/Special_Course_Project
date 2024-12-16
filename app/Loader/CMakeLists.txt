cmake_minimum_required(VERSION 3.14)

project(Loader
        VERSION 1.0
        DESCRIPTION "Save data to DataBase"
        LANGUAGES CXX
       )

include_directories(include)

aux_source_directory(src ALL_SOURCES)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PostgreSQL REQUIRED)

add_executable(Loader main.cpp ${ALL_SOURCES})
target_link_libraries(Loader PRIVATE PostgreSQL::PostgreSQL)
