#ifndef CSED232_IO_H
#define CSED232_IO_H
#include <fstream>
#include <iostream>

using namespace std;

class Stream {
public:
    ifstream _in;
    ofstream _out;
    streambuf *_cin;
    explicit Stream(streambuf* _cin);
    template <typename T> T in();
};

#endif //CSED232_IO_H
