cmake_minimum_required(VERSION 3.13)
project(pi)
set(CMAKE_CXX_STANDARD 14)

add_executable(pi pi.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(pi PUBLIC OpenMP::OpenMP_CXX)
endif()