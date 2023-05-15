cmake_minimum_required(VERSION 3.20)
project(Boxes)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS s-box.h p-box.h tests.h)
set(SOURCES main.cpp s-box.cpp p-box.cpp tests.cpp)

add_subdirectory(testing/googletest)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest_main gtest)