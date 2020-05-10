#include "Tetromino.h"
#include "BlockList.h"

Tetromino::Tetromino(int x, int y, BlockList& blockList) {
    for(auto& i: blocks){
        i = blockList.add();
    }

    blockPosition[0].setPosition(0, 0);
    blockPosition[1].setPosition(1, 0);
    blockPosition[2].setPosition(2, 0);
    blockPosition[3].setPosition(3, 0);
    this->color = BLUE;
    this->axis_idx = 0;
    initTetromino(x, y);
}
