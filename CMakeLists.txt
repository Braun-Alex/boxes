cmake_minimum_required(VERSION 3.20)
project(Boxes)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS s-box.h)
set(SOURCES main.cpp s-box.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})