#ifndef CSED232_BLOCKLIST_H
#define CSED232_BLOCKLIST_H

#include "Block.h"
#include "const.h"

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

    BlockList() {
        for(auto&i: blockList){
            i = nullptr;
        }
    };
};


#endif //CSED232_BLOCKLIST_H
