#include "Board.h"
#include "const.h"
#include "Block.h"
#include "BlockList.h"
#include "Tetromino.h"



void Board::reset() {
    for(auto& i : gameBoard){
        for(auto& j: i){
            j = nullptr;
        }
    }
}

void Board::printLine(bool isEndl, int num) {
    for(int i=0; i < num; i++){
        cout << SEP;
    }
    if(isEndl) cout << endl;
}

void Board::getCurrentBlocks(Block **currentBlocks) {
    int size = 0;
    for(auto& i: gameBoard){
        for(auto& j: i){
            if(j != nullptr && !(j->isStop())) {
                currentBlocks[size++] = j;
            }
            if(size == 4) { break; }
        }
    }
}

int Board::getHeight(int x) {
    for(int i = ROW - 1; i >=0; i--){
        if(gameBoard[CONVERT_Y(i)][x] != nullptr && gameBoard[CONVERT_Y(i)][x]->isStop()){
            return i;
        }
    }
    return 0;
}

Board::Board(BlockList &list) {
    this->blockList = &list;
    for(auto & i : gameBoard){
        for(auto & j : i){
            j = nullptr;
        }
    }

    for(auto&i: infoTable){
        for(auto&j: i){
            j = " ";
        }
    }

}

void Board::set() {
    reset();
    for(int i = 0; i < MAX_BLOCK; i++){
        auto tmp = blockList->at(i);
        if(tmp != nullptr){
            int y = ROW - tmp->y() - 1;
            if((0 <= y && y < ROW) && (0 <= tmp->x() && tmp->x() < COL)){
                auto boardPoint = gameBoard[y][tmp->x()];
                if((boardPoint == nullptr) || boardPoint->isShadow())
                    gameBoard[y][tmp->x()] = tmp;
            }
        }
    }
}

void Board::setOneBlock(Block *target, int x, int y) {
    y = ROW - y - 1;
    if((0 <= y && y < ROW) && (0 <= x && x < COL)){
        gameBoard[y][x] = target;
    }
}

void Board::render(Tetromino *currentMino, Tetromino *nextMino, int score) {
    makeShadow(currentMino);
    renderInfoBoard(nextMino, score);
    this->set();
    system("clear");
    printLine(true, COL + INFO_LEN + 3);
    int row = 0;
    for(auto& i : gameBoard){
        cout << SEP;
        for(auto& j: i){
            if(j == nullptr){
                cout << " ";
            } else {
                j->show();
            }
        }
        cout << SEP;
        if(row < INFO_HEIGHT){
            for(auto&k : infoTable[row]){
                cout << k;
            }
            cout << SEP;
        }

        if(row == INFO_HEIGHT){
            printLine(false, INFO_LEN + 1);
        }

        cout << endl;
        row++;
    }
    printLine(true, COL + 2);
    deleteShadow();
}

void Board::renderInfoBoard(Tetromino* nextMino, int Score){
    Position axis(INFO_LEN / 2, 2);
    initInfoBoard();
    for(int i = 0; i < 4; i++){
        Block& tmp = nextMino->getBlockByIdx(i);
        infoTable[axis.y() - tmp.rel_y()][axis.x() + tmp.rel_x()] = tmp.toString();
    }
}

void Board::initInfoBoard(){
    for(auto&i:infoTable){
        for(auto&j:i){
            j = " ";
        }
    }
}

Block *Board::XY(int x, int y) {
    if((0 <= x && x < COL) && (0 <= y && y < ROW)){
        return (gameBoard[ROW - y - 1][x]);
    } else {
        return nullptr;
    }
}

void Board::setShadowOn(bool isOn) {
    this->isShadowOn = isOn;
}

void Board::shadowSwitch(){
    this->isShadowOn = !isShadowOn;
}

void Board::makeShadow(Tetromino* currentMino) {
    if(!isShadowOn){
        return;
    }

    string targetStr = "□";

    shadow = new Tetromino(*blockList, this);
    *shadow = *currentMino;
    shadow->setShadowMino(true);
    shadow->setStr(targetStr);
    shadow->hardDrop();
}

void Board::deleteShadow(){
    if(!isShadowOn){
        return;
    }
    delete shadow;
    blockList->removeShadow();
}
