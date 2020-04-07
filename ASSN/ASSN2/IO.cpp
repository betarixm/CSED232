#include "IO.h"

Stream::Stream(streambuf* _cin){
        this->_cin = _cin;
}

template <typename T> T Stream::in(){
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
