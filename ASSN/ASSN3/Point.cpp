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

Point::Point(int axis_x, int axis_y, int rel_x, int rel_y) {
    axis.setPosition(axis_x, axis_y);
    relative.setPosition(rel_x, rel_y);
}

Point::Point(Position _axis, Position _relative) {
    axis.setPosition(_axis.x(), _axis.y());
    relative.setPosition(_relative.x(), _relative.y());
}

int Point::x() {
    return axis.x() + relative.x();
}

int Point::y() {
    return axis.y() + relative.y();
}

void Point::setAxis(int x, int y) {
    axis.setPosition(x, y);
}

void Point::setRelative(int x, int y) {
    relative.setPosition(x, y);
}

Point &Point::operator+(Position &param) {
    axis += param;
    return *this;
}

Point &Point::operator-(Position &param) {
    axis -= param;
    return *this;
}

Point &Point::operator+=(Position param) {
    axis += param;
    return *this;
}

Point &Point::operator-=(Position param) {
    axis -= param;
    return *this;
}

Point &Point::operator=(const Point& param) {
    if(&param != this) {
        relative = param.relative;
        axis = param.axis;
    }
    return *this;
}





