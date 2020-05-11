#ifndef CSED232_GAME_H
#define CSED232_GAME_H

#include <mutex>
#include <iostream>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "Stack.h"
#include "Tetromino.h"
#include "const.h"

using namespace std;

class Game {
private:
    int unitTick = 100000000;
    int inputTick = 100000;
    unsigned int process = 0;
    BlockList* blockList;
    Board* board;
    Stack<char>* inputStack;
    Stack<Tetromino*> minoStack;
    mutex* m;
    Tetromino* t;

    char getInput(){
        char tmp = 0;
        m->lock();
        bool res = inputStack->pop(tmp);
        m->unlock();
        if(res){
            return tmp;
        } else {
            return -1;
        }
    }

    bool parseInput(){
        char input = getInput();
        if(input == 'a'){
            t->move(-1, 0);
        } else if (input == 'd') {
            t->move(1, 0);
        } else if (input == 's') {
            t->move(0, -1);
        } else if (input == 'w') {
            t->rotate(CW);
        } else if (input == 'x') {
            t->rotate(CCW);
        } else if (input == 'm') {

        } else if (input == ' ') {

        } else {
            return false;
        }

        return true;
    }

    void setTetromino(){
        // Todo:  not random!
        if(t != nullptr){
            minoStack.push(t);
        }
        t = new Tetromino(1, 18, *blockList, board);
    }

public:
    Game(BlockList* _blockList, Board* _board, Stack<char>* _inputStack, mutex* _m){
        blockList = _blockList;
        board = _board;
        inputStack = _inputStack;
        m = _m;
        t = nullptr;
        setTetromino();
    }

    void run(){
        while(++process){
            if(process % inputTick == 0){
                if(parseInput()){
                    board->render();
                }
            }

            if(process % unitTick == 0){
                t->onTick();
                board->render();
                process = 0;
                if(t->isStop()){
                    setTetromino();
                }
            }
        }
    }
};


#endif //CSED232_GAME_H
