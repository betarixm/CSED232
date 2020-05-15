#include "Block.h"
#include "const.h"
#include <iostream>

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

/**
 * @brief 블럭을 출력하는 생성자
 */
void Block::show() {
    cout << this->toString(); // colored text 출력
}

/**
 * @brief 블럭을 색상있는 문자열로 리턴하는 메서드 (ANSI COLOR)
 * @return 블럭의 colored string
 */
string Block::toString(){
    string tmp;
    // ANSI 컬러 코드를 포함한 문자열을 반환.
    tmp = "\x1b[" + to_string(color) + "m" + str + "\x1b[" + to_string(RESET) + "m";
    return tmp;
}
/**
 * 좌표들을 정수형으로 받는 생성자
 * @param axis_x x 축좌표
 * @param axis_y y 축좌표
 * @param relative_x x 상대좌표
 * @param relative_y y 상대좌표
 * @param color 색상 코드
 */
Block::Block(int axis_x, int axis_y, int relative_x, int relative_y, int color) {
    p.setAxis(axis_x, axis_y); // 블럭의 축 설정
    p.setRelative(relative_x, relative_y); // 블럭의 상대 좌표 설정
    this->color = color; // 블럭 색상 설정
}

/**
 * @brief 좌표들을 Position으로 받는 생성자
 * @param axis 축좌표 Position
 * @param relative 상대좌표 Position
 * @param color 색상 코드
 */
Block::Block(Position axis, Position relative, int color) {
    p.setAxis(axis); // 블럭 축 설정
    p.setRelative(relative); // 블럭의 상대 좌표 설정
    this->color = color; // 블럭 색상 설정

}

/**
 * @brief 블럭의 축 좌표 지정 메서드
 * @param x x 축 좌표
 * @param y y 축 좌표
 */
void Block::setAxis(int x, int y) {
    p.setAxis(x, y); // 블럭의 축 좌표 지정
}

/**
 * @brief 블럭 이동 메서드
 * @param dx 움직일 x 거리
 * @param dy 움직일 y 거리
 */
void Block::move(int dx, int dy) {
    p+=Position(dx, dy); // 블럭의 축 좌표 덧셈 수행
}

/**
 * @brief 블럭 상대 좌표를 정수형으로 지정하는 메서드
 * @param x
 * @param y
 */
void Block::setRelative(int x, int y) {
    p.setRelative(x, y); // 블럭의 상대 좌표 지정
}

/**
 * @brief 블럭 상대 좌표를 Position으로 지정하는 메서드
 */
void Block::setRelative(Position _p) {
    p.setRelative(_p); // 블럭의 상대 좌표 지정
}

/**
 * @brief 블럭 색상 지정 메서드
 * @param _color 지정할 색상
 */
void Block::setColor(int _color) {
    this->color = _color; // 블럭의 컬러 지정
}

/**
 * @brief 블럭의 x 절대 좌표 반환 메서드
 * @return 블럭의 x 절대 좌표
 */
int Block::x() {
    return p.x(); // 블럭의 x 절대 좌표 반환
}

/**
 * @brief 블럭의 y 절대 좌표 반환 메서드
 * @return 블럭의 y 절대 좌표
 */
int Block::y() {
    return p.y(); // 블럭의 y 절대 좌표 반환
}

/**
 * @brief 블럭의 x 상대 좌표 반환 메서드
 * @return 블럭의 x 상대 좌표
 */
int Block::rel_x() {
    return p.rel_x(); // 블럭의 x 상대 좌표 반환
}

/**
 * @brief 블럭의 y 상대 좌표 반환 메서드
 * @return 블럭의 y 상대 좌표
 */
int Block::rel_y() {
    return p.rel_y(); // 블럭의 y 상대 좌표 반환
}

/**
 * @brief 블럭 회전 메서드
 * @param direction 회전 방향을 지정
 */
void Block::rotate(int direction) {
    p.rotate(direction); // 좌표 회전 메서드 호출
}

/**
 * @brief 블럭의 멈춤 여부 반환하는 메서드
 * @return 블럭의 멈춤 여부
 */
bool &Block::isStop() {
    return isStoppedBlock; // 블럭 정지 여부 반환
}

/**
 * @brief 블럭의 축 좌표에 +=
 * @param param 상대 파라미터
 * @return 더해진 결과의 참조형
 */
Block &Block::operator+=(Position param) {
    p += param; // 블럭 축 좌표 덧셈
    return *this;
}

/**
 * @brief 블럭의 축 좌표에 -=
 * @param param 상대 파라미터
 * @return 더해진 결과의 참조형
 */
Block &Block::operator-=(Position param) {
    p -= param; // 블럭 축 좌표 뺄셈
    return *this;
}

/**
 * @brief 블럭의 변수 값들 대입
 * @param param 상대 파라미터
 * @return 더해진 결과의 참조형
 */
Block &Block::operator=(const Block &param) {
    if (&param != this) {
        // 색상, 포인트, 정지여부, 그림자 여부 복사
        color = param.color;
        p = param.p;
        isStoppedBlock = param.isStoppedBlock;
        isShadowBlock = param.isShadowBlock;
    }
    return *this;
}

/**
 * @brief 블럭의 문자열 지정
 * @param s 블럭에 지정할 문자열
 */
void Block::setStr(string &s) {
    this->str.assign(s);
}

/**
 * @brief 블럭의 그림자 여부 반환
 * @return 블럭의 그림자 여부
 */
bool &Block::isShadow() {
    return isShadowBlock;
}
