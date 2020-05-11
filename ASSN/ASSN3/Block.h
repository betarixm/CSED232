#ifndef CSED232_BLOCK_H
#define CSED232_BLOCK_H

#include "Point.h"
#include <iostream>
using namespace std;

class Point;
class Block {
private:
    Point p {0, 0, 0, 0};
    int color;
    string str = "■";
    bool isStoppedBlock = false;

public:
    Block(int axis_x, int axis_y, int relative_x, int relative_y, int color);
    Block(Position axis, Position relative, int color){
        p.setAxis(axis);
        p.setRelative(relative);
        this->color = color;

    }
    void show();
    void setAxis(int x, int y){
        p.setAxis(x, y);
    }

    void setRelative(int x, int y){
        p.setRelative(x, y);
    }

    void setRelative(Position _p){
        p.setRelative(_p);
    }

    void setColor(int _color){
        this->color = _color;
    }

    int x(){
       return p.x();
    }

    int y(){
        return p.y();
    }

    void rotate(int direction){
        p.rotate(direction);
    }

    bool& isStop(){
        return isStoppedBlock;
    }

    Block&operator+=(Position param){
        p += param;
        return *this;
    }

    Block&operator-=(Position param){
        p -= param;
        return *this;
    }
};


#endif //CSED232_BLOCK_H
