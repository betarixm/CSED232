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

/**
 * @brief 정수 좌표를 입력받는 Point 클래스 생성자
 * @param axis_x x 절대 좌표
 * @param axis_y y 절대 좌표
 * @param rel_x x 상대 좌표
 * @param rel_y y 상대 좌표
 */
Point::Point(int axis_x, int axis_y, int rel_x, int rel_y) {
    axis.setPosition(axis_x, axis_y); // 축 좌표 설정
    relative.setPosition(rel_x, rel_y); // 상대 좌표 설정
}

/**
 * @brief Position을 입력받는 Point 클래스 생성자
 * @param _axis 축 좌표
 * @param _relative 상대 좌표
 */
Point::Point(Position _axis, Position _relative) {
    axis.setPosition(_axis.x(), _axis.y()); // 축 좌표 설정
    relative.setPosition(_relative.x(), _relative.y()); // 상대 좌표 설정
}

/**
 * @brief x 절대 좌표를 반환하는 메서드
 * @return x 절대 좌표
 */
int Point::x() {
    return axis.x() + relative.x();
}

/**
 * @brief y 절대 좌표를 반환하는 메서드
 * @return y 절대 좌표
 */
int Point::y() {
    return axis.y() + relative.y();
}

/**
 * @brief 축 좌표를 설정하는 메서드
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 */
void Point::setAxis(int x, int y) {
    axis.setPosition(x, y); // 축 좌표 설정
}

/**
 * @brief 상대 좌표를 설정하는 메서드
 * @param x x 상대 좌표
 * @param y y 상대 좌표
 */
void Point::setRelative(int x, int y) {
    relative.setPosition(x, y); // 상대 좌표 설정
}

/**
 * @brief 축 좌표에 더하는 + 오버로딩
 * @param param 대상 Position 오브젝트
 */
Point &Point::operator+(Position &param) {
    axis += param;
    return *this;
}

/**
 * @brief 축 좌표에서 빼는 - 오버로딩
 * @param param 대상 Position 오브젝트
 */
Point &Point::operator-(Position &param) {
    axis -= param;
    return *this;
}

/**
 * @brief 축 좌표에 더하는 += 오버로딩
 * @param param 대상 Position 오브젝트
 */
Point &Point::operator+=(Position param) {
    axis += param;
    return *this;
}

/**
 * @brief 축 좌표에서 빼는 -= 오버로딩
 * @param param 대상 Position 오브젝트
 */
Point &Point::operator-=(Position param) {
    axis -= param;
    return *this;
}

/**
 * @brief 축 좌표와 상대 좌표를 대입하는 = 오버로딩
 * @param param 대상 Point 오브젝트
 */
Point &Point::operator=(const Point& param) {
    if(&param != this) {
        relative = param.relative; // 상대 좌표 대입
        axis = param.axis; // 축 좌표 대입
    }
    return *this;
}

/**
 * @brief x 상대 좌표를 반환하는 메서드
 * @return x 상대 좌표
 */
int Point::rel_x() {
    return relative.x();
}

/**
 * @brief y 상대 좌표를 반환하는 메서드
 * @return y 상대 좌표
 */
int Point::rel_y() {
    return relative.y();
}

/**
 * @brief Position으로 축을 설정하는 메서드
 * @param p 축이 될 Position
 */
void Point::setAxis(Position p) {
    axis.setPosition(p);
}

/**
 * @brief Position으로 상대 좌표를 설정하는 메서드
 * @param p 상대 좌표 Position
 */
void Point::setRelative(Position p) {
    relative.setPosition(p);
}

/**
 * @brief 좌표를 회전하는 메서드
 * @param direction
 */
void Point::rotate(int direction) {
    // 회전 행렬을 연산하듯이 좌표를 회전시킨다.
    relative.swap();
    if(direction == CW){
        relative.y() *= -1; // 시계 방향일 경우 y 좌표에 * -1
    } else if (direction == CCW) {
        relative.x() *= -1; // 반시계 방향일 경우 x 좌표에 * -1
    }
}





