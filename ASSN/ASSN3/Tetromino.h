#ifndef CSED232_TETROMINO_H
#define CSED232_TETROMINO_H

#include "Block.h"
#include "const.h"
#include "Board.h"
#include "unistd.h"

class Block;
class BlockList;

class Tetromino {
private:
    void setSRSDataSet(Position set[][5]){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 5; j++){
                SRSDataSet[i][j] = set[i][j];
            }
        }
    }
protected:
    Block* blocks[4]{};
    Board* board;
    Position SRSDataSet[8][5]{};
    int axis_idx = 0;
    int color = RESET;
    int rotate_num = 1;

    Position blockPosition[4];

    void initTetromino(int x, int y){
        SRSTestSetGenerator();
        for(int i = 0; i < 4; i++){
            blocks[i]->setAxis(x, y);
            blocks[i]->setRelative(blockPosition[i]);
            blocks[i]->setColor(this->color);
        }
    }

    bool isHit(int dx, int dy){
        for(auto& i: blocks){
            int x = i->x() + dx;
            int y = i->y() + dy;

            if((!((0 <= x && x < COL) && (0 <= y && y < ROW))) || (board->XY(x, y) != nullptr && board->XY(x, y)->isStop())){
                return true;
            }
        }
        return false;
    }

    virtual void SRSTestSetGenerator(){
        Position virtualSet[8][5] = {
                {Position( 0, 0), Position(-1, 0), Position(-1,-1), Position( 0,+2), Position(-1,+2)}, // L -> 2
                {Position( 0, 0), Position(-1, 0), Position(-1,-1), Position( 0,+2), Position(-1,+2)}, // L -> 0
                {Position( 0, 0), Position(+1, 0), Position(+1,+1), Position( 0,-2), Position(+1,-2)}, // 0 -> L
                {Position( 0, 0), Position(-1, 0), Position(-1,+1), Position( 0,-2), Position(-1,-2)}, // 0 -> R
                {Position( 0, 0), Position(+1, 0), Position(+1,-1), Position( 0,+2), Position(+1,+2)}, // R -> 0
                {Position( 0, 0), Position(+1, 0), Position(+1,-1), Position( 0,+2), Position(+1,+2)}, // R -> 2
                {Position( 0, 0), Position(-1, 0), Position(-1,+1), Position( 0,-2), Position(-1,-2)}, // 2 -> R
                {Position( 0, 0), Position(+1, 0), Position(+1,+1), Position( 0,-2), Position(+1,-2)}  // 2 -> L
        };

        setSRSDataSet(virtualSet);
    }

public:
    Tetromino(int x, int y, BlockList& blockList, Board* _board);

    void rotate(int direction){
        int cursor = rotate_num * 2 + (direction + 1) / 2;

        for(auto& i: blocks){
            i->rotate(direction);
        }

        for(auto& i: SRSDataSet[cursor]){

            cout << "Now Testing...: (" << i.x() << ", " << i.y() << ")" <<  endl;
            cout << "Before XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            for(auto& b: blocks){ (*b) += i; }

            cout << "After XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            if(isHit(0, 0)){
                cout << "FAIL!" << endl;
                for(auto& b: blocks){ (*b) -= i; }
                cout << "Back to XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            } else {
                rotate_num += direction;
                rotate_num = (rotate_num < 0) ? (3) : ((3 < rotate_num) ? (0) : (rotate_num));
                return;
            }
        }

        for(auto& i: blocks){
            i->rotate(-1 * direction);
        }
        sleep(10000000);

    }

    void move(int dx, int dy){
        if(isHit(dx, dy)) return;
        for(auto& i: blocks){
            if(!i->isStop()){
                *i += Position(dx, dy);
            }
        }
    }

    int stop(){
        for(auto& i: blocks){
            i->isStop() = true;
        }
        return 0;
    }

    bool checkStop(){
        board->set();
        for(auto& i: blocks){
            if(i->y() == 0){
                return true;
            }
            Block* test = board->XY(i->x(), i->y() - 1);
            if(test != nullptr && test->isStop()){
                return true;
            }
        }
        return false;
    }

    bool isStop(){
        for(auto& i:blocks){
            if(i->isStop()){
                return true;
            }
        }
        return false;
    }

    void onTick(){
        checkStop() && stop();
        move(0, -1);
    }
};


#endif //CSED232_TETROMINO_H
