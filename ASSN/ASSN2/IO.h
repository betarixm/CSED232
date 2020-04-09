#ifndef CSED232_IO_H
#define CSED232_IO_H
#include <iostream>
#include <fstream>

using namespace std;

class Stream;

class Stream {
public:
    ifstream _in;
    ofstream _out;
    streambuf *_cin;
    explicit Stream(streambuf* _cin);
    template <typename T> T in();
};

#endif //CSED232_IO_H
