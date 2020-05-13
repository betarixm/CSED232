#ifndef CSED232_GAME_H
#define CSED232_GAME_H

#include <mutex>
#include <iostream>
#include <random>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "Stack.h"
#include "Tetromino.h"
#include "const.h"

#define NUM_TETROMINO 7
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
    bool isUsed[NUM_TETROMINO] {false, };

    void initUsedArray(){
        for(auto& i: isUsed){
             i = false;
        }
    }

    bool isAllUsed(){
        for(auto& i : isUsed){
            if(!i) return false;
        }
        return true;
    }
    Tetromino* getTetrimino(){
        int num = 0;

        do {
            if(isAllUsed()){ initUsedArray(); }
            num = rand() % NUM_TETROMINO;
        } while(isUsed[num]);

        isUsed[num] = true;

        Tetromino* result;
        switch(num){
            case MINO_I:
                result = new Mino_I(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_O:
                result = new Mino_O(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_T:
                result = new Mino_T(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_L:
                result = new Mino_L(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_J:
                result = new Mino_J(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_S:
                result = new Mino_S(COL / 2, ROW - 1, *blockList, board);
                break;
            case MINO_Z:
                result = new Mino_Z(COL / 2, ROW - 1, *blockList, board);
                break;
            default:
                result = nullptr;
                break;
        }

        return result;

    }
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
            t->hardDrop();
        } else {
            return false;
        }

        return true;
    }

    void setTetromino(){
        if(t != nullptr){
            minoStack.push(t);
        }
        t = getTetrimino();
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
