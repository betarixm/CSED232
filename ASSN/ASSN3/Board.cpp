#include "Board.h"
#include "const.h"
#include "Block.h"
#include "BlockList.h"
#include "Tetromino.h"
#include "IO.h"

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

    for(auto&i: infoboard){
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

void Board::render(Tetromino *currentMino, Tetromino *nextMino, int score, int combo) {
    makeShadow(currentMino);
    renderInfoBoard(nextMino, score, combo);
    this->set();
    clear();
    printLine(true, COL + INFO_COL + 3);
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
        if(row < INFO_ROW){
            for(auto&k : infoboard[row]){
                cout << k;
            }
            cout << SEP;
        }

        if(row == INFO_ROW){
            printLine(false, INFO_COL + 1);
        }

        cout << endl;
        row++;
    }
    printLine(true, COL + 2);
    deleteShadow();
}

void Board::renderInfoBoard(Tetromino *nextMino, int score, int combo) {
    Position axis(INFO_COL / 2 , 2);
    string info_text[4] = {
            " Score",
            " " + to_string(score),
            " Combo",
            " " + to_string(combo)
    };

    initInfoBoard();
    for(int i = 0; i < 4; i++){
        Block& tmp = nextMino->getBlockByIdx(i);
        infoboard[axis.y() - tmp.rel_y()][axis.x() + tmp.rel_x()] = tmp.toString();
    }

    for(int i = 0; i < INFO_COL; i++){
        infoboard[INFO_ROW / 3 * 1][i] = SEP;
        infoboard[INFO_ROW / 3 * 2][i] = SEP;
    }

    for(int i = 0; i < 4; i++){
        int tmp_idx = 0;
        int process = (i < 2)?(1):(2);
        for(auto& l: infoboard[INFO_ROW / 3 * process + 2 + i % 2]){
            l = info_text[i][tmp_idx++];
            if(tmp_idx == info_text[i].length()) break;
        }
    }

}

void Board::initInfoBoard(){
    for(auto&i:infoboard){
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