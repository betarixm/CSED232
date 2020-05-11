#include "Tetromino.h"
#include "BlockList.h"

Tetromino::Tetromino(int x, int y, BlockList& blockList, Board* _board) {
    for(auto& i: blocks){
        i = blockList.add();
    }

    blockPosition[0].setPosition(1, 1);
    blockPosition[1].setPosition(-1, 0);
    blockPosition[2].setPosition(0, 0);
    blockPosition[3].setPosition(1, 0);
    this->color = WHITE;
    this->axis_idx = 0;
    this->board = _board;
    initTetromino(x, y);
}
