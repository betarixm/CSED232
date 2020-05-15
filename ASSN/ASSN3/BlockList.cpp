#include "BlockList.h"

#include <iostream>
#include "Block.h"

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

/**
 * @brief 블록 리스트에 블록을 등록하고 반환하는 메서드
 * @param axis_x 축 x 좌표
 * @param axis_y 축 y 좌표
 * @param rel_x 상대 x 좌표
 * @param rel_y 상대 y 좌표
 * @param color 블럭 색상
 * @return 생성된 블럭의 주소
 */
Block *BlockList::add(int axis_x, int axis_y, int rel_x, int rel_y, int color) {
    for(auto & i : blockList){ // 블록 주소 배열 탐색
        if(i == nullptr){
            // 비어있는 배열에 새로운 블록 할당
            i = new Block(axis_x, axis_y, rel_x, rel_y, color);
            size++;
            return i; // 블록 주소 반환
        }
    }
    return nullptr; // 실패했을 경우 nullptr 반환
}

/**
 * @brief 임의의 블록을 리스트에 추가하는 메서드
 * @param target 추가할 블록의 주소
 * @return 추가된 블록의 주소
 */
Block *BlockList::append(Block *target) {
    for(auto&i: blockList){
        if(i == nullptr){
            // 배열의 비어있는 곳에 추가할 블록의 주소 할당
            i = target;
            size++;
            return target; // 블록 주소 반환
        }
    }
    return nullptr; // 실패했을 경우 nullptr 반환
}

/**
 * @brief 특정 인덱스의 블록 주소 반환하는 메서드
 * @param idx 인덱스
 * @return 특정 블록의 주소
 */
Block *BlockList::at(int idx) {
    return blockList[idx];
}

/**
 * @brief 그림자 블록을 삭제하는 메서드
 */
void BlockList::removeShadow() {
    for(auto&i: blockList){
        // 블록 배열 탐색 중 그림자인 블록을 발견하면
        if(i != nullptr && i->isShadow()){
            delete i; // 할당 해제하고
            i = nullptr; // nullptr을 지정한다.
        }
    }
}

/**
 * @brief 줄 삭제 메서드를 초기화하는 메서드
 * @param simulateBoard 시뮬레이션 보드 배열 참조
 * @param line_size 줄 크기 배열 참조
 */
void BlockList::initRemoveLines(int (*simulateBoard)[10], int *line_size) {

    // 시뮬레이션 보드와 줄 크기 배열을 지정된 값으로 초기화
    for(int row = 0; row < ROW; row ++){
        line_size[row] = 0;
        for(int col = 0; col < COL; col++){
            simulateBoard[row][col] = MAX_BLOCK;
        }
    }

    for(int i = 0; i < MAX_BLOCK; i++){
        // 블럭 리스트를 탐색하면서 블럭을 발견했을 때,
        if(i != MAX_BLOCK && blockList[i] != nullptr) {
            Block* tmp = blockList[i];
            int y = tmp->y();
            int x = tmp->x();
            // 블럭이 보드 범위 안에 들어올 경우, 시뮬레이션 보드에 등록한다.=
            if(!(tmp->isShadow()) && 0 <= y && y < ROW && 0 <= x && x < COL) {
                simulateBoard[y][x] = i;
                line_size[y]++; // 해당 줄의 사이즈 증가
            }
        }
    }
}

/**
 * @brief 줄을 삭제하는 메서드
 * @return 삭제한 줄 수
 */
int BlockList::removeLines() {
    int num_removed = 0;

    int simulateBoard[ROW][COL] = {NULL, }; // 시뮬레이션 보드 선언
    int sizes[ROW] = {0, }; // 각 줄 크기를 담을 배열 선언

    initRemoveLines(simulateBoard, sizes); // 배열들 초기화

    // 시뮬레이션 보드 탐색.
    for(int i = 0; i < ROW; i++){
        if(sizes[i] == COL){ // 사이즈가 꽉 찼을 경우에
            for(int j : simulateBoard[i]){ // 블럭들을 삭제한다.
                delete blockList[j];
                blockList[j] = nullptr;
            }

            // 현재 줄보다 위에 있는 멈춘 블럭들을 한칸씩 이동시킨다.
            for(auto& block: blockList){
                if(block != nullptr && block->y() > i && ( !block->isShadow() && block->isStop())){
                    block->move(0, -1);
                }
            }

            // 다시 보드를 초기화 한다.
            initRemoveLines(simulateBoard, sizes);

            // 블럭이 모두 움직였으므로, i를 하나 줄인다.
            // 삭제한 줄 수 증가
            i--, num_removed++;
        }
    }

    return num_removed;
}

/**
 * @brief 게임 오버인지 확인하는 메서드
 * @return 게임 오버 여부
 */
bool BlockList::isGameOver() {
    // 블록 리스트를 탐색
    for(auto& i : blockList){
        // 게임보드 바깥에 멈춘 블럭이 발견되면
        if(i != nullptr && i->isStop() && i->y() >= ROW){
            return true; // 게임 오버 되었음을 반환
        }
    }
    return false; // 게임 오버가 아님을 반환
}

/**
 * @brief 블럭 리스트 생성자
 */
BlockList::BlockList() {
    // 블럭 리스트 배열을 초기화한다.
    for(auto&i: blockList){
        i = nullptr;
    }
}

/**
 * @brief 블럭 리스트 소멸자
 */
BlockList::~BlockList() {
    // 할당된 블럭들을 해제한다.
    for(auto& i : blockList){
        delete(i);
    }
}
