#ifndef CSED232_TETROMINO_H
#define CSED232_TETROMINO_H

#include "Block.h"
#include "const.h"

class Block;
class BlockList;

class Tetromino {
protected:
    Block* blocks[4];
    int axis_idx = 0;
    int color = RESET;

    Position blockPosition[4];

    void initTetromino(int x, int y){
        for(int i = 0; i < 4; i++){
            blocks[i]->setAxis(x, y);
            blocks[i]->setRelative(blockPosition[i]);
            blocks[i]->setColor(this->color);
        }
    }

public:
    Tetromino(int x, int y, BlockList& blockList);
};


#endif //CSED232_TETROMINO_H
