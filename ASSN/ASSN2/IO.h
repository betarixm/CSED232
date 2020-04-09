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
    explicit Stream(streambuf* _cin){
        this->_cin = _cin;
    }
    template <typename T> T in(){
        if(_in.is_open()){
            cin.rdbuf(_in.rdbuf());
        } else {
            cin.rdbuf(_cin);
        }

        T input;
        cin >> input;
        _out << input << endl;
        return input;
    }
};

#endif //CSED232_IO_H

