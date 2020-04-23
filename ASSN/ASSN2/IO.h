#ifndef CSED232_IO_H
#define CSED232_IO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
using namespace std;

class Stream;

/**
 * @brief 입출력 Wrapper 클래스
 * @details 파일이나 콘솔을 이용하여 입력받아야하고,
 *          로그로 남겼다가 남기지 말았다가 해야 하고,
 *          심지어 로그 파일과 커맨드 파일의 파일명이 같아서 이를 관리해야 하는 등
 *          입출력 과정이 복잡하여 이를 관리하기 위한 IO wrapper 클래스이다.
 */
class Stream {
private:
    ifstream _in; /// @brief command.txt 입력 스트림
    ofstream _out; /// @brief command.txt 출력 스트림
    streambuf *_cin; /// @brief cin의 원본 버퍼 저장

    /// @brief 로그 파일에 로그를 남기는 메서드
    template<typename T>
    void log(T &input);

    /// @brief command.txt가 EOF에 도달했는지 검사하는 메서드
    void checkEOF();

    /// @brief 마지막 로그를 삭제하는 메서드
    void removeLastLog();

public:
    /// @brief Stream 클래스 생성자
    explicit Stream(streambuf *_cin);

    /// @brief 사용자나 커맨드 파일로부터 int 입력을 수행하는 메서드
    bool getInt(int &input);

    /// @brief std::getline의 Wrapper 메서드
    void getLine(string &input);

    /// @brief command.txt의 스트림을 여는 메서드
    void loadCommand();

    /// @brief command.txt로부터 입력받는 모드인지 그 여부를 반환하는 메서드
    bool isLoadingCommand();

};

#endif //CSED232_IO_H

