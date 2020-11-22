cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(vec3 LANGUAGES CXX)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(main PRIVATE include)