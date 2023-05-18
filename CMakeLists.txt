cmake_minimum_required(VERSION 3.24)
project(Ray_Tracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ray_Tracer main.cpp vec3.h color.h ray.h)
