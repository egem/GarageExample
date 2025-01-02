cmake_minimum_required(VERSION 3.31)

project("Vehicle")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} sources)

add_executable(main main.cpp ${sources})

target_compile_features(main PRIVATE cxx_std_17)
