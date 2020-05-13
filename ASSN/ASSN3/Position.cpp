
#include "Position.h"

int &Position::x() {
    return pos_x;
}

int &Position::y() {
    return pos_y;
}


void Position::setPosition(int x, int y) {
    pos_x = x;
    pos_y = y;
}


Position &Position::operator+(Position param) {
    this->pos_x += param.pos_x;
    this->pos_y += param.pos_y;
    return *this;
}

Position &Position::operator=(const Position& param) {
    if(&param != this) {
        this->pos_x = param.pos_x;
        this->pos_y = param.pos_y;
    }
    return *this;
}

Position &Position::operator-(Position param) {
    this->pos_x -= param.pos_x;
    this->pos_y -= param.pos_y;
    return *this;
}

Position &Position::operator+=(Position param) {
    this->operator+(param);
    return *this;
}

Position &Position::operator-=(Position &param) {
    this->operator-(param);
    return *this;
}



