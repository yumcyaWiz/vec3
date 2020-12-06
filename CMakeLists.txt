cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0076 NEW)

project(vec3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hitSphere hitSphere.cpp)
target_include_directories(hitSphere PRIVATE include)

add_executable(vecAdd vecAdd.cpp)
target_include_directories(vecAdd PRIVATE include)