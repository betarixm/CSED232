#ifndef CSED232_POINT_H
#define CSED232_POINT_H

#include "Position.h"
#include "const.h"

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
 * @brief 블럭의 좌표를 관리하는 클래스
 */
class Point {
private:
    Position relative; /// @brief 축으로부터의 상대 좌표
    Position axis; /// @brief 축의 좌표

public:
    /// @brief 정수 좌표를 입력받는 Point 클래스 생성자
    Point(int rel_x, int rel_y, int axis_x, int axis_y);

    /// @brief Position을 입력받는 Point 클래스 생성자
    Point(Position _axis, Position _relative);

    /// @brief x 절대 좌표를 반환하는 메서드
    int x();

    /// @brief y 절대 좌표를 반환하는 메서드
    int y();

    /// @brief x 상대 좌표를 반환하는 메서드
    int rel_x();

    /// @brief y 상대 좌표를 반환하는 메서드
    int rel_y();

    /// @brief 축 좌표를 설정하는 메서드
    void setAxis(int x, int y);

    /// @brief Position으로 축을 설정하는 메서드
    void setAxis(Position p);

    /// @brief 상대 좌표를 설정하는 메서드
    void setRelative(int x, int y);

    /// @brief Position으로 상대 좌표를 설정하는 메서드
    void setRelative(Position p);

    /// @brief 좌표를 회전하는 메서드
    void rotate(int direction);

    /// @brief 축 좌표에 더하는 + 오버로딩
    Point&operator+(Position& param);

    /// @brief 축 좌표에서 빼는 - 오버로딩
    Point&operator-(Position& param);

    /// @brief 축 좌표에 더하는 += 오버로딩
    Point&operator+=(Position param);

    /// @brief 축 좌표에서 빼는 -= 오버로딩
    Point&operator-=(Position param);

    /// @brief 축 좌표와 상대 좌표를 대입하는 = 오버로딩
    Point&operator=(const Point& param);
};


#endif //CSED232_POINT_H
