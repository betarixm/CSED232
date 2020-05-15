cmake_minimum_required(VERSION 3.15)
project(CSED232)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")


# add_executable(PLAY playground/playground.cpp)
add_executable(ASSN1_1 ASSN/ASSN1/prob_1/prob_1.cpp)
add_executable(ASSN1_2 ASSN/ASSN1/prob_2/prob_2.cpp)
add_executable(ASSN1_3 ASSN/ASSN1/prob_3/prob_3.cpp)

file(GLOB ASSN2_CPP ASSN/ASSN2/*.cpp)
file(GLOB ASSN2_H ASSN/ASSN2/*.h)
file(COPY ASSN/ASSN2/command.txt DESTINATION ${CMAKE_BINARY_DIR})
add_executable(ASSN2 ASSN/ASSN2/20190084.cpp ${ASSN2_CPP} ${ASSN2_H})

file(GLOB ASSN3_H ASSN/ASSN3/*.h)
file(GLOB ASSN3_CPP ASSN/ASSN3/*.cpp)
add_executable(ASSN3 ${ASSN3_H} ${ASSN3_CPP})