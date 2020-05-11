#include <iostream>
#include <thread>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "const.h"
#include "Tetromino.h"
#include "Stack.h"
#include "IO.h"
#include "Game.h"

using namespace std;

int main(){
    BlockList blockList;
    Board board(blockList);
    Stack<char> inputStack;
    mutex m;
    thread thInput(input, ref(inputStack), ref(m));

    Game game(&blockList, &board, &inputStack, &m);

    game.run();
    thInput.join();
}