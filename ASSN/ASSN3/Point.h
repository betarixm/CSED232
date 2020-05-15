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

class Position;

class Point {
private:
    Position relative;
    Position axis;

public:

    Point(int rel_x, int rel_y, int axis_x, int axis_y);

    Point(Position _axis, Position _relative);

    int x();

    int y();

    int rel_x(){
        return relative.x();
    }

    int rel_y(){
        return relative.y();
    }
    void setAxis(int x, int y);

    void setAxis(Position p){
        axis.setPosition(p);
    }
    void setRelative(int x, int y);

    void setRelative(Position p){
        relative.setPosition(p);
    }

    void rotate(int direction){
        relative.swap();
        if(direction == CW){
            relative.y() *= -1;
        } else if (direction == CCW) {
            relative.x() *= -1;
        }
    }

    Point&operator+(Position& param);

    Point&operator-(Position& param);

    Point&operator+=(Position param);

    Point&operator-=(Position param);

    Point&operator=(const Point& param);
};


#endif //CSED232_POINT_H
