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
    Position SRSDataSet[8][5]{};
    int color = RESET;
    int rotate_num = 1;

    Position blockPosition[4];

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

protected:
    Block* blocks[4]{};
    Board* board{};
    void setSRSDataSet(Position set[][5]){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 5; j++){
                SRSDataSet[i][j] = set[i][j];
            }
        }
    }

    virtual void initTetromino(int x, int y){
        SRSTestSetGenerator();
        color = colorGenerator();
        blockGenerator(blockPosition);
        for(int i = 0; i < 4; i++){
            blocks[i]->setAxis(x, y);
            blocks[i]->setRelative(blockPosition[i]);
            blocks[i]->setColor(this->color);
        }
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

    virtual void blockGenerator(Position* _blockPosition)  {
        _blockPosition[0].setPosition(1, 1);
        _blockPosition[1].setPosition(-1, 0);
        _blockPosition[2].setPosition(0, 0);
        _blockPosition[3].setPosition(1, 0);
    }

    virtual int colorGenerator(){
        return WHITE;
    }

    int axis_idx = 0;
public:
    Tetromino() = default;
    Tetromino(BlockList& blockList, Board* _board){
        for(auto& i: blocks){
            i = blockList.add();
        }
        this->axis_idx = 0;
        this->board = _board;
    }

    virtual void rotate(int direction){
        int cursor = rotate_num * 2 + (direction + 1) / 2;

        for(auto& i: blocks){
            i->rotate(direction);
        }

        for(auto& i: SRSDataSet[cursor]){

            // cout << "Now Testing...: (" << i.x() << ", " << i.y() << ")" <<  endl;
            // cout << "Before XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            for(auto& b: blocks){ (*b) += i; }

            // cout << "After XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            if(isHit(0, 0)){
                // cout << "FAIL!" << endl;
                for(auto& b: blocks){ (*b) -= i; }
                // cout << "Back to XY: (" << blocks[0]->x() << ", " << blocks[0]->y() << ")" << endl;

            } else {
                rotate_num += direction;
                rotate_num = (rotate_num < 0) ? (3) : ((3 < rotate_num) ? (0) : (rotate_num));
                return;
            }
        }

        for(auto& i: blocks){
            i->rotate(-1 * direction);
        }

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

    void hardDrop(){
        for(int dy = 0; dy >= (-1 * ROW); dy--){
            if(isHit(0, dy - 1)){
                move(0, dy);
                break;
            }
        }
    }
};

class Mino_I: public Tetromino{
private:
    void SRSTestSetGenerator() override{
        Position virtualSet[8][5] = {
                { Position( 1,  0), Position(-1,  0), Position( 2,  0), Position(-1, -1), Position( 2,  2) },
                { Position( 0,  1), Position( 1,  1), Position(-2,  1), Position( 1, -1), Position(-2,  2) },
                { Position( 0, -1), Position(-1, -1), Position( 2, -1), Position(-1,  1), Position( 2, -2) },
                { Position( 1,  0), Position(-1,  0), Position( 2,  0), Position(-1, -1), Position( 2,  2) },
                { Position(-1,  0), Position( 1,  0), Position(-2,  0), Position( 1,  1), Position(-2, -2) },
                { Position( 0, -1), Position(-1, -1), Position( 2, -1), Position(-1,  1), Position( 2, -2) },
                { Position( 0,  1), Position( 1,  1), Position(-2,  1), Position( 1, -1), Position(-2,  2) },
                { Position(-1,  0), Position( 1,  0), Position(-2,  0), Position( 1,  1), Position(-2, -2) }
        };

        setSRSDataSet(virtualSet);
    }

    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition(-1, 0);
        _blockPosition[1].setPosition(0, 0);
        _blockPosition[2].setPosition(1, 0);
        _blockPosition[3].setPosition(2, 0);
    }

    int colorGenerator() override {
        return CYAN;
    }

public:
    Mino_I(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_I::initTetromino(x, y);
    };
};


class Mino_O: public Tetromino{

private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition(0,  0);
        _blockPosition[1].setPosition(1,  0);
        _blockPosition[2].setPosition(0, -1);
        _blockPosition[3].setPosition(1, -1);
    }

    int colorGenerator() override {
        return YELLOW;
    }
    
public:
    Mino_O(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_O::initTetromino(x, y);
    };;

    void rotate(int direction) override { }
};


class Mino_T: public Tetromino{
private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition( 0,  1);
        _blockPosition[1].setPosition(-1,  0);
        _blockPosition[2].setPosition( 0,  0);
        _blockPosition[3].setPosition( 1,  0);
    }

    int colorGenerator() override {
        return MAGENTA;
    }
    
public:
    Mino_T(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_T::initTetromino(x, y);
    };

};

class Mino_L: public Tetromino{
private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition( 1,  1);
        _blockPosition[1].setPosition(-1,  0);
        _blockPosition[2].setPosition( 0,  0);
        _blockPosition[3].setPosition( 1,  0);
    }

    int colorGenerator() override {
        return WHITE;
    }
    
public:
    Mino_L(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_L::initTetromino(x, y);
    };
};

class Mino_J: public Tetromino{
private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition(-1,  1);
        _blockPosition[1].setPosition(-1,  0);
        _blockPosition[2].setPosition( 0,  0);
        _blockPosition[3].setPosition( 1,  0);
    }

    int colorGenerator() override {
        return BLUE;
    }
public:
    Mino_J(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_J::initTetromino(x, y);
    };
};

class Mino_S: public Tetromino{
private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition( 0,  1);
        _blockPosition[1].setPosition( 1,  1);
        _blockPosition[2].setPosition(-1,  0);
        _blockPosition[3].setPosition( 0,  0);
    }

    int colorGenerator() override {
        return GREEN;
    }
public:
    Mino_S(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board) {
        Mino_S::initTetromino(x, y);
    };
};

class Mino_Z: public Tetromino{
private:
    void blockGenerator(Position* _blockPosition) override{
        _blockPosition[0].setPosition( -1,  1);
        _blockPosition[1].setPosition( 0,  1);
        _blockPosition[2].setPosition( 0,  0);
        _blockPosition[3].setPosition( 1,  0);
    }

    int colorGenerator() override {
        return RED;
    }
public:
    Mino_Z(int x, int y, BlockList& _blockList, Board* _board): Tetromino(_blockList, _board){
        Mino_Z::initTetromino(x, y);
    };


};
#endif //CSED232_TETROMINO_H
