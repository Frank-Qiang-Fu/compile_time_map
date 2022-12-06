cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(compile_time_map)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/Catch2)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)