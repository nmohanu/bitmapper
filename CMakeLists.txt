cmake_minimum_required(VERSION 3.21)

project(bitmapper)

add_compile_options(-O3 -march=native)
set (CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 REQUIRED graphics window system)

add_executable(main main.cpp renderer.cpp input.cpp)

target_link_libraries(main sfml-graphics sfml-window sfml-system)
