
#ifndef CSED232_POSITION_H
#define CSED232_POSITION_H


class Position {
private:
    int pos_x = 0;
    int pos_y = 0;
public:
    int& x();
    int& y();
    void setPosition(int x, int y);

    Position& operator+(Position& param);

    Position& operator=(Position param);

    Position&operator-(Position& param);

    Position&operator+=(Position& param);

    Position&operator-=(Position& param);

};


#endif //CSED232_POSITION_H
