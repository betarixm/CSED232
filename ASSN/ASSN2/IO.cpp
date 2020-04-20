#include "IO.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

template<typename T>
void Stream::log(T &input) {
    if (!_in.is_open()) {
        this->_out.open("command.txt", ios::app);
        _out << input << endl;
        this->_out.close();
    }
}

void Stream::checkEOF() {
    if (_in.is_open() && _in.peek() == EOF) {
        _in.close();
    }
}

void Stream::removeLastLog() {
    ifstream fileTmp("command.txt");
    stringstream buffer;
    buffer << fileTmp.rdbuf();
    string strResult = buffer.str();
    fileTmp.close();
    strResult.pop_back();
    strResult.pop_back();
    if (strResult.back() != '\n')
        strResult.push_back('\n');
    ofstream fileResult("command.txt", ios::trunc);
    fileResult << strResult;
    fileResult.close();
}

Stream::Stream(streambuf *_cin) {
    this->_cin = _cin;
}

bool Stream::getInt(int &input) {
    bool result;
    string input_str;
    this->getLine(input_str);
    try {
        input = stoi(input_str);
        result = true;
    } catch (...) {
        result = false;
    }
    return result;
}

void Stream::getLine(string &input) {
    if (_in.is_open()) {
        cin.rdbuf(_in.rdbuf());
    } else {
        cin.rdbuf(_cin);
    }
    std::getline(cin, input);
    (_in.is_open()) && (cout << "" << input << endl);
    this->log<string>(input);
    checkEOF();
}

void Stream::loadCommand() {
    this->removeLastLog();
    _in.open("command.txt", ios::in);
    if (_in.fail()) {
        cout << "Load Command Failed." << endl;
        _in.close();
    }
}

bool Stream::isLoadingCommand() {
    return _in.is_open();
}



