#ifndef CSED232_IO_H
#define CSED232_IO_H

#include "Stack.h"
#include "Queue.h"
#include <mutex>
#include <iostream>
#include <unistd.h>

void input(Queue<char> &inputStack, std::mutex &m, bool &isNotPause, bool &isRun);

void logScore(int score);

void getLine(Queue<char> &inputQueue, std::string& result, bool display, std::mutex& m);

void clear();
void getChar(Queue<char>& inputQueue, char& result, std::mutex& m);

void showTitle();

void showGameOver();

void showLoading();
#endif //CSED232_IO_H
