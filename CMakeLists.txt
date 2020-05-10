cmake_minimum_required(VERSION 3.15)
project(CSED232)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
add_executable(play0319 playground/20200319.cpp)
add_executable(ASSN1_1 ASSN/ASSN1/prob_1/prob_1.cpp)
add_executable(ASSN1_2 ASSN/ASSN1/prob_2/prob_2.cpp)
add_executable(ASSN1_3 ASSN/ASSN1/prob_3/prob_3.cpp)

file(GLOB ASSN2_CPP ASSN/ASSN2/*.cpp)
file(GLOB ASSN2_H ASSN/ASSN2/*.h)
file(COPY ASSN/ASSN2/command.txt DESTINATION ${CMAKE_BINARY_DIR})
add_executable(ASSN2 ASSN/ASSN2/20190084.cpp ${ASSN2_CPP} ${ASSN2_H})

add_executable(ASSN3 ASSN/ASSN3/Block.cpp ASSN/ASSN3/Block.h ASSN/ASSN3/Point.cpp ASSN/ASSN3/Point.h ASSN/ASSN3/Position.cpp ASSN/ASSN3/Position.h ASSN/ASSN3/const.h ASSN/ASSN3/20190084.cpp)