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
    template <typename T> void in(T& input){
        if(_in.is_open()){
            cin.rdbuf(_in.rdbuf());
        } else {
            cin.rdbuf(_cin);
        }

        cin >> input;
        _out << input << endl;
        cin.ignore();
    }

    void getline(string& input){
        if(_in.is_open()){
            cin.rdbuf(_in.rdbuf());
        } else {
            cin.rdbuf(_cin);
        }
        std::getline(cin, input);
        _out << input << endl;
    }

    void ignore(){
        cin.ignore();
    }
};

#endif //CSED232_IO_H

