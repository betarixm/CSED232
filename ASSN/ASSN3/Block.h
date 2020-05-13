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
    bool isShadowBlock = false;

public:
    Block(int axis_x=0, int axis_y=0, int relative_x=0, int relative_y=0, int color=RESET);
    Block(Position axis, Position relative, int color){
        p.setAxis(axis);
        p.setRelative(relative);
        this->color = color;

    }
    void show();
    string toString();
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

    int rel_x(){
        return p.rel_x();
    }

    int rel_y(){
        return p.rel_y();
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

    Block& operator=(const Block& param){
        if (&param != this) {
            color = param.color;
            p = param.p;
            color = param.color;
            isStoppedBlock = param.isStoppedBlock;
        }
        return *this;
    }

    void setStr(string& s){
        this->str.assign(s);
    }

    bool& isShadow(){
        return isShadowBlock;
    }
};


#endif //CSED232_BLOCK_H
