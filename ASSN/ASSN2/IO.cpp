#include "IO.h"

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

/**
 * @brief 로그 파일에 로그를 남기는 메서드
 *
 * @tparam T 어떤 형식(자료형)이든지 기록할 수 있도록 템플릿화
 * @param input 로그 남길 내용
 */
template<typename T>
void Stream::log(T &input) {
    if (!_in.is_open()) { // command.txt의 읽기 스트림이 열려 있지 않을 경우에만
        this->_out.open("command.txt", ios::app); // 출력 스트림을 열어서
        _out << input << endl; // 로그 내용을 기록하고
        this->_out.close(); // 출력 스트림을 닫는다
    }
}

/**
 * @brief command.txt가 EOF에 도달했는지 검사하는 메서드
 */
void Stream::checkEOF() {
    // command.txt가 열려있는 상태이고, peek가 EOF라면 스트림을 닫는다.
    if (_in.is_open() && _in.peek() == EOF) {
        _in.close();
    }
}

/**
 * @brief 마지막 로그를 삭제하는 메서드
 * @details 3. Load command가 선택되었을 때, '3'이 로그에 기록되게 되면 의도하지 않은 동작이 발생할 수 있으므로 이를 삭제하는 역할을 수행한다.
 */
void Stream::removeLastLog() {
    if(!_in.is_open()){ // 로그 파일이 열려 있지 않다면
        _in.open("command.txt", ios::in); // 로그 파일을 연다
    }
    if(!_in.fail()){ // 로그 파일을 여는데 성공 했을 경우
        stringstream buffer; // 버퍼 스트링 스트림을 생성한다
        // 스트링스트림 버퍼를 이용하여 문자열로 로그를 저장한다.
        buffer << _in.rdbuf();
        string strResult = buffer.str();

        // 삭제하고자 하는 맨 마지막 로그 '3\n'을 삭제한다.
        strResult.pop_back();
        strResult.pop_back();

        // 정상적인 로그 작성을 위해 맨 뒤에 '\n'가 없는 경우 추가한다
        if (strResult.back() != '\n')
            strResult.push_back('\n');

        // 맨 마지막 로그를 삭제한 문자열을 파일에 기록한다
        _out.open("command.txt", ios::trunc);
        _out << strResult;
        _out.close();
    }

}

/**
 * @brief Stream 클래스 생성자
 * @details cin의 스트림버퍼를 클래스 안에 백업해두기 위해 오브젝트 생성 단계에서
 *          cin.rdbuf()를 미리 입력받아서 멤버 변수에 저장해둔다.
 * @param _cin 원본 cin의 버퍼를 입력받는다. explicit을 이용해 형 변환을 막는다.
 */
Stream::Stream(streambuf *_cin) {
    this->_cin = _cin; // 멤버 변수 _cin에 cin의 원본 버퍼를 저장
}

/**
 * @brief 사용자나 커맨드 파일로부터 int 입력을 수행하는 메서드
 *
 * @param input 입력 받은 값을 저장할 참조
 * @return 정상적으로 입력 받았는지 여부를 반환
 */
bool Stream::getInt(int &input) {
    bool result; // 정상적으로 입력 받았는지 여부를 저장
    string input_str; // 스트링으로 입력받을 임시 변수
    this->getLine(input_str); // 멤버 메서드 getLine을 이용하여 스트링 형태로 받아온다
    try {
        // 받아온 스트링을 int형으로 변환한다.
        input = stoi(input_str);
        result = true;
    } catch (...) {
        // stoi를 하는 과정에서 에러가 생겼다면 정상적으로 입력되지 않았음을 저장해준다.
        result = false;
    }
    return result; // 정상적으로 입력받았는지 그 여부를 반환한다.
}

/**
 * @brief std::getline의 Wrapper 메서드
 * @details std::getline()을 주어진 문제의 상황에 맞도록 사용자 입력이나 파일로부터 입력받는다.
 * @param input 입력 받은 값을 저장할 참조
 */
void Stream::getLine(string &input) {
    if (_in.is_open()) { // 만약 command.txt가 열려있다면,
        cin.rdbuf(_in.rdbuf()); // cin에 파일의 버퍼를 할당한다.
    } else { // 파일이 열려있지 않다면
        cin.rdbuf(_cin); // 백업해둔 원본 cin의 버퍼를 cin에 할당한다.
    }
    std::getline(cin, input); // cin으로 부터 getline을 수행해서 값을 저장한다.
    (_in.is_open()) && (cout << "[CMD] " << input << endl); // 만약 command.txt로 부터 가져온 값이라면, 그 값을 출력한다.
    this->log<string>(input); // 멤버 메서드 log를 호출하여 로그를 저장한다.
    checkEOF(); // 멤버 메서드 checkEOF를 호출하여 EOF일 경우 _in의 스트림을 닫는다.
}

/**
 * @brief command.txt의 스트림을 여는 메서드
 */
void Stream::loadCommand() {
    this->removeLastLog(); // command.txt를 로드하기 전에 오동작을 방지하여 마지막으로 기록된 로그를 삭제한다.
    _in.open("command.txt", ios::in); // command.txt 파일을 연다.
    if (_in.fail()) { // 파일을 여는데 실패했을 경우 에러 메세지를 띄우고 스트림을 닫는다.
        cout << "Load Command Failed." << endl;
        _in.close();
    }
}

/**
 * @brief command.txt로부터 입력받는 모드인지 그 여부를 반환하는 메서드
 * @return _in의 open 여부를 반환
 */
bool Stream::isLoadingCommand() {
    return _in.is_open(); // open 여부 반환
}



