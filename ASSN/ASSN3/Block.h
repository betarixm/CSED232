#ifndef CSED232_BLOCK_H
#define CSED232_BLOCK_H
#include <mutex>
#include <iostream>
#include "Point.h"

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

class Point;
class Position;

/**
 * @brief 블록 클래스
 */
class Block {
private:
    Point p {0, 0, 0, 0}; /// @brief 블럭의 좌표 저장
    int color; /// @brief 블럭 색상 지정
    string str = "■"; /// @brief 블럭의 표시 텍스트 지정
    bool isStoppedBlock = false; /// @brief 블럭의 멈춤 여부
    bool isShadowBlock = false; /// @brief 그림자 블럭 여부

public:
    /// @brief 좌표들을 정수형으로 받는 생성자
    explicit Block(int axis_x=0, int axis_y=0, int relative_x=0, int relative_y=0, int color=RESET);

    /// @brief 좌표들을 Position으로 받는 생성자
    Block(Position axis, Position relative, int color);

    /// @brief 블럭을 출력하는 생성자
    void show();

    /// @brief 블럭을 색상있는 문자열로 리턴하는 메서드 (ANSI COLOR)
    string toString();

    /// @brief 블럭의 축 좌표 지정 메서드
    void setAxis(int x, int y);

    /// @brief 블럭 이동 메서드
    void move(int dx, int dy);

    /// @brief 블럭 상대 좌표를 정수형으로 지정하는 메서드
    void setRelative(int x, int y);

    /// @brief 블럭 상대 좌표를 Position으로 지정하는 메서드
    void setRelative(Position _p);

    /// @brief 블럭 색상 지정 메서드
    void setColor(int _color);

    /// @brief 블럭의 x 절대 좌표 반환 메서드
    int x();

    /// @brief 블럭의 y 절대 좌표 반환 메서드
    int y();

    /// @brief 블럭의 x 상대 좌표 반환 메서드
    int rel_x();

    /// @brief 블럭의 y 상대 좌표 반환 메서드
    int rel_y();

    /// @brief 블럭 회전 메서드
    void rotate(int direction);

    /// @brief 블럭의 멈춤 여부 반환하는 메서드
    bool& isStop();

    /// @brief 블럭의 축 좌표에 +=
    Block&operator+=(Position param);

    /// @brief 블럭의 축 좌표에 -=
    Block&operator-=(Position param);

    /// @brief 블럭의 변수 값들 대입
    Block& operator=(const Block& param);

    /// @brief 블럭의 문자열 지정
    void setStr(string& s);

    /// @brief 블럭의 그림자 여부 반환
    bool& isShadow();
};


#endif //CSED232_BLOCK_H
