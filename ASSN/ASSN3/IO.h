#ifndef CSED232_IO_H
#define CSED232_IO_H

#include "Stack.h"
#include "Queue.h"
#include <mutex>
#include <iostream>
#include <unistd.h>

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

/// @brief 사용자로부터 입력을 받는 스레드로 실행될 함수
void input(Queue<char> &inputStack, std::mutex &m, bool &isNotPause, bool &isRun);

/// @brief 로그를 저장하는 함수
void logScore(int score);

/// @brief 터미널을 클리어하는 함수
void clear();

/// @brief 공유 인풋 큐에서 입력을 가져오는 함수
void getChar(Queue<char>& inputQueue, char& result, std::mutex& m);

/// @brief 게임 타이틀 아스키 아트를 출력하는 함수
void showTitle();

/// @brief 게임 오버 아스키 아트를 출력하는 함수
void showGameOver();

/// @brief 게임 로딩 아스키 아트를 출력하는 함수
void showLoading();

#endif //CSED232_IO_H
