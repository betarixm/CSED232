#ifndef CSED232_BLOCKLIST_H
#define CSED232_BLOCKLIST_H

#include "Block.h"
#include "const.h"
#include "Stack.h"

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

template <typename T>
class Stack;

/**
 * @brief 블록들을 관리하는 클래스
 */
class BlockList {
private:
    int size = 0; /// @brief 블럭 개수
    Block* blockList[MAX_BLOCK] {}; /// @brief 블럭 주소 배열

    /// @brief 줄 삭제 메서드를 초기화하는 메서드
    void initRemoveLines(int simulateBoard[][COL], int line_size[ROW]);

public:
    /// @brief 블록 리스트에 블록을 등록하고 반환하는 메서드
    Block* add(int axis_x = 0, int axis_y = 0, int rel_x = 0, int rel_y = 0, int color = RESET);

    /// @brief 임의의 블록을 리스트에 추가하는 메서드
    Block* append(Block* target);

    /// @brief 특정 인덱스의 블록 주소 반환하는 메서드
    Block* at(int idx);

    /// @brief 그림자 블록을 삭제하는 메서드
    void removeShadow();

    /// @brief 줄을 삭제하는 메서드
    int removeLines();

    /// @brief 게임 오버인지 확인하는 메서드
    bool isGameOver();

    /// @brief 블럭 리스트 생성자
    BlockList();;
};


#endif //CSED232_BLOCKLIST_H
