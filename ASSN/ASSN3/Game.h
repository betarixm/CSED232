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
#include "Queue.h"
#include "IO.h"
#define NUM_TETROMINO 7

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

using namespace std;

class Game {
private:
    int unitTick = 100000000;
    int inputTick = 100000;
    double coefficient = 1;
    int score = 0;
    unsigned int process = 0;
    BlockList* blockList;
    Board* board;
    Queue<char>* inputQueue;
    Stack<Tetromino*> minoStack;
    mutex* m;
    Tetromino* t;
    Tetromino* next_t;
    bool isUsed[NUM_TETROMINO] {false, };
    int combo = 0;

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
                result = new Mino_I(COL / 2, ROW, *blockList, board);
                break;
            case MINO_O:
                result = new Mino_O(COL / 2, ROW + 1, *blockList, board);
                break;
            case MINO_T:
                result = new Mino_T(COL / 2, ROW, *blockList, board);
                break;
            case MINO_L:
                result = new Mino_L(COL / 2, ROW, *blockList, board);
                break;
            case MINO_J:
                result = new Mino_J(COL / 2, ROW, *blockList, board);
                break;
            case MINO_S:
                result = new Mino_S(COL / 2, ROW, *blockList, board);
                break;
            case MINO_Z:
                result = new Mino_Z(COL / 2, ROW, *blockList, board);
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
        bool res = inputQueue->pop(tmp);
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
            t->move(-1, 0, false);
        } else if (input == 'd') {
            t->move(1, 0, false);
        } else if (input == 's') {
            t->move(0, -1, false);
        } else if (input == 'w') {
            t->rotate(CW);
        } else if (input == 'x') {
            t->rotate(CCW);
        } else if (input == 'm') {
            board->shadowSwitch();
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
        t = next_t;
        next_t = getTetrimino();
    }

public:
    Game(BlockList* _blockList, Board* _board, Queue<char> *_inputQueue, mutex* _m){
        blockList = _blockList;
        board = _board;
        inputQueue = _inputQueue;
        m = _m;
        t = nullptr;
        next_t = getTetrimino();
        setTetromino();
    }

    int run(){
        while(++process){
            if(process % inputTick == 0){
                if(parseInput()){
                    board->render(t, next_t, score, combo);
                }
            }

            if(process % (int)(unitTick/coefficient) == 0){
                t->onTick();

                checkScore(blockList->removeLines());
                board->render(t, next_t, score, combo);
                if(blockList->isGameOver()){
                    return score;
                }
                process = 0;
                if(t->isStop()){
                    setTetromino();
                }
            }
        }
        return 0;
    }

    void checkScore(int num_lines) {
        int partial_score = 0;
        if(num_lines == 0){
            if(combo > 0 && t->isStop()) combo = 0;
            return;
        } else if(num_lines == 1) {
            partial_score = 100;
        } else if(num_lines == 2) {
            partial_score = 300;
        } else if (num_lines == 3) {
            partial_score = 500;
        } else if (num_lines >= 4) {
            partial_score = 1000;
        }
        combo++;

        if(combo >= 2){
            partial_score += 100 * (combo - 1);
        }

        score += partial_score;
        coefficient = 1 + ((int)(score/1000))/10;
    }

    bool checkSaveLog(){
        char input;
        while(true){
            flush(cout);
            cin.clear();
            system("echo \"Do you want to save your score? [PRESS (y/n)]\"");
            // cout << "Do you want to save your score? [PRESS (y/n)] ";
            getChar(*inputQueue, input, *m);
            cout << input << endl;

            if(input == 'y') {
                logScore(score);
                return true;
            } else if (input == 'n') {
                return false;
            } else {
                cout << "Please input 'y' or 'n'" << endl;
            }
            cout << endl;
        }
    }

    bool checkRestart(){
        char input;
        while(true){
            flush(cout);
            cin.clear();
            system("echo \"Do you want to restart? [PRESS (y/n)]\"");
            // cout << "Do you want to restart? [PRESS (y/n)] ";
            getChar(*inputQueue, input, *m);
            cout << input << endl;
            if(input == 'y'){
                return true;
            } else if (input == 'n'){
                return false;
            } else {
                cout << "Please press 'y' or 'n'" << endl;
            }
            cout << endl;
        }
    }

};


#endif //CSED232_GAME_H
