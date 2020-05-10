#include <iostream>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "const.h"
#include "Tetromino.h"

using namespace std;

int main(){
    BlockList blockList;
    Board board(blockList);
    Tetromino test(0, 0, blockList);

    board.render();
}