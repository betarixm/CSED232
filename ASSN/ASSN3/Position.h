#ifndef CSED232_POSITION_H
#define CSED232_POSITION_H

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

class Position {
private:
    int pos_x = 0;
    int pos_y = 0;
public:
    Position() = default;
    Position(int x, int y){
        pos_x = x;
        pos_y = y;
    }
    int& x();
    int& y();

    void setPosition(int x, int y);
    void setPosition(Position p){
        pos_x = p.x();
        pos_y = p.y();
    }

    void swap(){
        int tmp = pos_x;
        pos_x = pos_y;
        pos_y = tmp;
    }

    Position& operator+(Position param);

    Position& operator=(const Position & param);

    Position&operator-(Position param);

    Position&operator+=(Position param);

    Position&operator-=(Position& param);

};


#endif //CSED232_POSITION_H
