cmake_minimum_required(VERSION 3.14)
project(CG_2019_Assignment3 C)

set(CMAKE_C_STANDARD 99)

find_package(GLUT)
find_package(OpenGL)

add_executable(bomb src/main.c)

target_link_libraries(bomb GLUT::GLUT OpenGL::GL)