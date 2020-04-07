cmake_minimum_required(VERSION 3.15)
project(CSED232)

set(CMAKE_CXX_STANDARD 14)

add_executable(play0319 playground/20200319.cpp)
add_executable(ASSN1_1 ASSN/ASSN1/prob_1/prob_1.cpp)
add_executable(ASSN1_2 ASSN/ASSN1/prob_2/prob_2.cpp)
add_executable(ASSN1_3 ASSN/ASSN1/prob_3/prob_3.cpp)

add_executable(ASSN2 ASSN/ASSN2/20190084.cpp ASSN/ASSN2/Comment.cpp ASSN/ASSN2/Comment.h ASSN/ASSN2/User.cpp ASSN/ASSN2/User.h ASSN/ASSN2/IO.cpp ASSN/ASSN2/IO.h ASSN/ASSN2/Post.cpp ASSN/ASSN2/Post.h ASSN/ASSN2/Menu.cpp ASSN/ASSN2/Menu.h ASSN/ASSN2/Utils.cpp ASSN/ASSN2/Utils.h ASSN/ASSN2/20190084.h)