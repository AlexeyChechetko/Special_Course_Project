cmake_minimum_required(VERSION 3.14)

project(Commander
        VERSION 1.0
        DESCRIPTION "Commander part of project"
        LANGUAGES CXX
)

include_directories(include)

aux_source_directory(src ALL_SOURCES)

add_executable(Commander main.cpp ${ALL_SOURCES})
