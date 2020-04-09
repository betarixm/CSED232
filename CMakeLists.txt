cmake_minimum_required(VERSION 3.15)
project(CSED232)

set(CMAKE_CXX_STANDARD 11)

add_executable(play0319 playground/20200319.cpp)
add_executable(ASSN1_1 ASSN/ASSN1/prob_1/prob_1.cpp)
add_executable(ASSN1_2 ASSN/ASSN1/prob_2/prob_2.cpp)
add_executable(ASSN1_3 ASSN/ASSN1/prob_3/prob_3.cpp)

file(GLOB ASSN2_CPP ASSN/ASSN2/*.cpp)
file(GLOB ASSN2_H ASSN/ASSN2/*.h)
add_executable(ASSN2 ${ASSN2_CPP} ${ASSN2_H})