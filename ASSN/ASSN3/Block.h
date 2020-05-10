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

public:
    Block(int axis_x, int axis_y, int relative_x, int relative_y, int color);
    void show();
};


#endif //CSED232_BLOCK_H
