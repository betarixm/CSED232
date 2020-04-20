#ifndef CSED232_IO_H
#define CSED232_IO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

using namespace std;

class Stream;

class Stream {
private:
    ifstream _in;
    ofstream _out;
    streambuf *_cin;

    template<typename T>
    void log(T &input);

    void checkEOF();

    void removeLastLog();

public:
    explicit Stream(streambuf *_cin);

    bool getInt(int &input);

    void getLine(string &input);

    void loadCommand();

    bool isLoadingCommand();

};

#endif //CSED232_IO_H

