#ifndef CSED232_BOARD_H
#define CSED232_BOARD_H

#include <iostream>

#define ROW 20
#define COL 10
#define SEP ("■")
#define BLK (" ")

#define INFO_LEN 7
#define INFO_HEIGHT 5

#define CONVERT_Y(Y) (ROW-Y-1)


class Block;
class BlockList;
class Tetromino;

using namespace std;

class Board {
private:
    Block* gameBoard[ROW][COL]{};
    Tetromino* shadow;
    Block* shadowBlocks[4];

    BlockList* blockList;

    string infoTable[INFO_HEIGHT][INFO_LEN];

    void reset();

    void printLine(bool isEndl, int num);

    bool isShadowOn = true;

    void getCurrentBlocks(Block* currentBlocks[4]);

    int getHeight(int x);

public:
    explicit Board(BlockList& list);

    void set();

    void setOneBlock(Block* target, int x, int y);

    void render(Tetromino *currentMino, Tetromino *nextMino, int score);

    void renderInfoBoard(Tetromino* nextMino, int Score);

    Block* XY(int x, int y);

    void setShadowOn(bool isOn);

    void shadowSwitch();

    void makeShadow(Tetromino* currentMino);

    void deleteShadow();

    void initInfoBoard();
};


#endif //CSED232_BOARD_H
