#ifndef CSED232_BOARD_H
#define CSED232_BOARD_H

#include "const.h"
#include "Block.h"
#include "BlockList.h"
#include <iostream>
#define ROW 20
#define COL 3
#define SEP ("■")

class Block;
class BlockList;

using namespace std;

class Board {
private:
    Block* gameBoard[ROW][COL]{};
    BlockList* blockList;
    void reset(){
        for(auto& i : gameBoard){
            for(auto& j: i){
                j = nullptr;
            }
        }
    }

    void printLine(bool isEndl){
        for(int i=0; i < (COL + 2); i++){
            cout << SEP;
        }
        if(isEndl) cout << endl;
    }
public:
    explicit Board(BlockList& list){
        this->blockList = &list;
        for(auto & i : gameBoard){
            for(auto & j : i){
                j = nullptr;
            }
        }
    }

    void set(){
        reset();
        for(int i = 0; i < MAX_BLOCK; i++){
            auto tmp = blockList->at(i);
            if(tmp != nullptr){
                int y = ROW - tmp->y() - 1;
                if((0 <= y && y < ROW) && (0 <= tmp->x() && tmp->x() < COL)){
                    gameBoard[y][tmp->x()] = tmp;
                }
            }
        }
    }

    void render(){
        this->set();
        system("clear");
        printLine(true);
        for(auto& i : gameBoard){
            cout << SEP;
            for(auto& j: i){
                if(j == nullptr){
                    cout << " ";
                } else {
                    j->show();
                }
            }
            cout << SEP << endl;
        }
        printLine(true);
    }

    Block* XY(int x, int y){
        if((0 <= x && x < COL) && (0 <= y && y < ROW)){
            return (gameBoard[ROW - y - 1][x]);
        } else {
            return nullptr;
        }
    }
};


#endif //CSED232_BOARD_H
