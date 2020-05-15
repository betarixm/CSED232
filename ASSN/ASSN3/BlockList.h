#ifndef CSED232_BLOCKLIST_H
#define CSED232_BLOCKLIST_H

#include "Block.h"
#include "const.h"
#include "Stack.h"

template <typename T>
class Stack;

class BlockList {
private:
    int size = 0;
    Block* blockList[MAX_BLOCK] {};

public:
    Block* add(int axis_x = 0, int axis_y = 0, int rel_x = 0, int rel_y = 0, int color = RESET){
        for(auto & i : blockList){
            if(i == nullptr){
                i = new Block(axis_x, axis_y, rel_x, rel_y, color);
                size++;
                return i;
            }
        }
        return nullptr;
    }

    Block* add(Position axis, Position rel, int color = RESET){
        for(auto & i : blockList){
            if(i == nullptr){
                i = new Block(axis, rel, color);
                size++;
                return i;
            }
        }
        return nullptr;
    }

    Block* append(Block* target){
        for(auto&i: blockList){
            if(i == nullptr){
                i = target;
                size++;
                return target;
            }
        }
        return nullptr;
    }

    Block* at(int idx){
        return blockList[idx];
    }

    void remove(Block* target){
        for(auto & i : blockList){
            if(i == target){
                delete i;
                i = nullptr;
                break;
            }
        }
    }

    void removeShadow(){
        for(auto&i: blockList){
            if(i != nullptr && i->isShadow()){
                delete i;
                i = nullptr;
            }
        }
    }

    void initRemoveLines(int lines[][COL], int sizes[ROW]){

        for(int row = 0; row < ROW; row ++){
            sizes[row] = 0;
            for(int col = 0; col < COL; col++){
                lines[row][col] = MAX_BLOCK;
            }
        }
        for(int i = 0; i < MAX_BLOCK; i++){
            if(i != MAX_BLOCK && blockList[i] != nullptr) {
                Block* tmp = blockList[i];
                int y = tmp->y();
                int x = tmp->x();
                if(!(tmp->isShadow()) && 0 <= y && y < ROW && 0 <= x && x < COL) {
                    lines[y][x] = i;
                    sizes[y]++;
                }
            }
        }
    }

    int removeLines(){
        int num_removed = 0;

        int lines[ROW][COL] = {NULL, };
        int sizes[ROW] = {0, };

        initRemoveLines(lines, sizes);

        for(int i = 0; i < ROW; i++){
            if(sizes[i] == COL){
                for(int j : lines[i]){
                    delete blockList[j];
                    blockList[j] = nullptr;
                }

                for(auto& block: blockList){
                    if(block != nullptr && block->y() > i && ( !block->isShadow() && block->isStop())){
                        block->move(0, -1);
                    }
                }

                initRemoveLines(lines, sizes);
                i--, num_removed++;
            }
        }

        return num_removed;
    }

    bool isGameOver(){
        for(auto& i : blockList){
            if(i != nullptr && i->isStop() && i->y() >= ROW){
                return true;
            }
        }
        return false;
    }

    BlockList() {
        for(auto&i: blockList){
            i = nullptr;
        }
    };
};


#endif //CSED232_BLOCKLIST_H
