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

/**
 * @brief x 좌표를 반환하는 메서드
 * @return x 좌표
 */
int &Position::x() {
    return pos_x;
}

/**
 * @brief y 좌표를 반환하는 메서드
 * @return y 좌표
 */
int &Position::y() {
    return pos_y;
}

/**
 * @brief 정수형으로 좌표를 설정하는 메서드
 * @param x x 좌표
 * @param y y 좌표
 */
void Position::setPosition(int x, int y) {
    pos_x = x;
    pos_y = y;
}

/**
 * @brief 좌표를 더하는 + 오버로딩
 * @param param 상대 Position
 */
Position &Position::operator+(Position param) {
    this->pos_x += param.pos_x;
    this->pos_y += param.pos_y;
    return *this;
}

/**
 * @brief 좌표를 대입하는 = 오버로딩
 * @param param 상대 Position
 */
Position &Position::operator=(const Position& param) {
    if(&param != this) {
        this->pos_x = param.pos_x;
        this->pos_y = param.pos_y;
    }
    return *this;
}

/**
 * @brief 좌표를 빼는 - 오버로딩
 * @param param 상대 Position
 */
Position &Position::operator-(Position param) {
    this->pos_x -= param.pos_x;
    this->pos_y -= param.pos_y;
    return *this;
}

/**
 * @brief 좌표를 더하는 += 오버로딩
 * @param param 상대 Position
 */
Position &Position::operator+=(Position param) {
    this->operator+(param);
    return *this;
}

/**
 * @brief 좌표를 빼는 -= 오버로딩
 * @param param 상대 Position
 */
Position &Position::operator-=(Position &param) {
    this->operator-(param);
    return *this;
}

/**
 * @brief 정수 좌표로 초기화하는 Position 생성자
 * @param x x 좌표
 * @param y y 좌표
 */
Position::Position(int x, int y) {
    pos_x = x;
    pos_y = y;
}

/**
 * @brief Position으로 좌표를 설정하는 메서드
 * @param p 설정할 Position
 */
void Position::setPosition(Position p) {
    pos_x = p.x();
    pos_y = p.y();
}

/**
 * @brief x와 y 좌표 값을 바꿔주는 메서드
 */
void Position::swap() {
    int tmp = pos_x;
    pos_x = pos_y;
    pos_y = tmp;
}



