cmake_minimum_required(VERSION 3.14)
project(OptionPricer
        VERSION 1.0
        DESCRIPTION "Count price of option"
        LANGUAGES CXX
)

include_directories(include)

aux_source_directory(src ALL_SOURCES)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PostgreSQL REQUIRED)

add_executable(OptionPricer main.cpp ${ALL_SOURCES})
target_link_libraries(OptionPricer PRIVATE PostgreSQL::PostgreSQL)
