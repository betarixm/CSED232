#ifndef CSED232_BOARD_H
#define CSED232_BOARD_H

#include <iostream>
#include "const.h"

#define SEP ("■")
#define BLK (" ")

#define INFO_COL 9
#define INFO_ROW 15

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

    string infoboard[INFO_ROW][INFO_COL];

    void reset();

    void printLine(bool isEndl, int num);

    bool isShadowOn = true;

    void getCurrentBlocks(Block* currentBlocks[4]);

    int getHeight(int x);

public:
    explicit Board(BlockList& list);

    void set();

    void setOneBlock(Block* target, int x, int y);

    void render(Tetromino *currentMino, Tetromino *nextMino, int score, int combo);

    void renderInfoBoard(Tetromino *nextMino, int score, int combo);

    Block* XY(int x, int y);

    void setShadowOn(bool isOn);

    void shadowSwitch();

    void makeShadow(Tetromino* currentMino);

    void deleteShadow();

    void initInfoBoard();


};


#endif //CSED232_BOARD_H
