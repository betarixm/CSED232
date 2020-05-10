#ifndef CSED232_BOARD_H
#define CSED232_BOARD_H

#include "const.h"
#include "Block.h"
#include "BlockList.h"
#include <iostream>
#define ROW 20
#define COL 10

class Block;
class BlockList;

using namespace std;

class Board {
private:
    Block* gameBoard[ROW][COL]{};
    BlockList* blockList;
    void set(){
        for(int i = 0; i < MAX_BLOCK; i++){
            auto tmp = blockList->at(i);
            if(tmp != nullptr){
                gameBoard[tmp->y()][tmp->x()] = tmp;
            }
        }
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

    void render(){
        this->set();
        for(auto& i : gameBoard){
            for(auto& j: i){
                if(j == nullptr){
                    cout << " ";
                } else {
                    j->show();
                }
            }
            cout << endl;
        }
    }
};


#endif //CSED232_BOARD_H
