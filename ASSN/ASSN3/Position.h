
#ifndef CSED232_POSITION_H
#define CSED232_POSITION_H


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
