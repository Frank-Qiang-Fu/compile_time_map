cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(compile_time_map)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/Catch2)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)