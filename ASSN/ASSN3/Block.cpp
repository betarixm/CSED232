#include "Block.h"
#include "const.h"
#include <iostream>

using namespace std;

void Block::show() {
    cout << "\x1b[" << color << "m" << str << "\x1b[" << RESET << "m";
}

string Block::toString(){
    string tmp;
    tmp = "\x1b[" + to_string(color) + "m" + str + "\x1b[" + to_string(RESET) + "m";
    return tmp;
}

Block::Block(int axis_x, int axis_y, int relative_x, int relative_y, int color) {
    p.setAxis(axis_x, axis_y);
    p.setRelative(relative_x, relative_y);
    this->color = color;
}
