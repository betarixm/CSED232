cmake_minimum_required(VERSION 3.15)
project(CSED232)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")

find_package(Qt5Widgets REQUIRED)


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


file(GLOB ASSN4_H ASSN/ASSN4/*.h)
file(GLOB ASSN4_CPP ASSN/ASSN4/*.cpp)
add_executable(ASSN4 ${ASSN4_H} ${ASSN4_CPP})

file(GLOB ASSN5_H ASSN/ASSN5/*.h)
file(GLOB ASSN5_CPP ASSN/ASSN5/*.cpp)
add_executable(ASSN5 ${ASSN5_H} ${ASSN5_CPP})

target_link_libraries(ASSN5 Qt5::Widgets)

add_executable(FNL_05 EXAM/final/05.cpp)
add_executable(FNL_06 EXAM/final/06.cpp)
add_executable(FNL_07 EXAM/final/07.cpp)
add_executable(FNL_08 EXAM/final/08.cpp)
add_executable(FNL_08_SOL EXAM/final/08-sol.cpp)
add_executable(FNL_09 EXAM/final/09.cpp)
add_executable(FNL_10 EXAM/final/10.cpp)
add_executable(FNL_11_A EXAM/final/11-A.cpp)
add_executable(FNL_11_B EXAM/final/11-B.cpp)
add_executable(FNL_11_C EXAM/final/11-C.cpp)