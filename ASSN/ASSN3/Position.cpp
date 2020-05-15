#include "Position.h"

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



