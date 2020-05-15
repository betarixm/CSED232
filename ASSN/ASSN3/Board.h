#ifndef CSED232_BOARD_H
#define CSED232_BOARD_H

#include <iostream>
#include "const.h"

#define SEP ("■")
#define BLK (" ")

#define INFO_COL 9
#define INFO_ROW 15

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

class Block;
class BlockList;
class Tetromino;

using namespace std;

class Board {
private:
    Block* gameBoard[ROW][COL]{}; /// @brief 게임 보드 배열
    string infoBoard[INFO_ROW][INFO_COL]; /// @brief 정보 보드 배열

    Tetromino* shadow; /// @brief 그림자 테트리미노
    BlockList* blockList; /// @brief 이 보드에서 사용할 블록 리스트 오브젝트

    bool isShadowOn = true; /// @brief 그림자 출력 여부

    /// @brief 게임 보드를 초기화 하는 메서드
    void initGameBoard();

    /// @brief 정보 보드 배열 초기화
    void initInfoBoard();

    /// @brief 정보 보드를 출력하기 위해 세팅하는 메서드
    void setInfoBoard(Tetromino *nextMino, int score, int combo);

    /// @brief 줄을 출력하는 메서드
    void printLine(bool isEndl, int num);

    /// @brief 그림자를 만드는 메서드
    void makeShadow(Tetromino* currentMino);

    /// @brief 그림자를 삭제하는 메서드
    void deleteShadow();

public:
    /// @brief 보드 클래스 생성자
    explicit Board(BlockList& list);

    /// @brief 보드 배열을 출력하기 위해 세팅하는 메서드
    void setGameBoard();

    /// @brief 게임을 렌더링하는 메서드
    void render(Tetromino *currentMino, Tetromino *nextMino, int score, int combo);

    /// @brief 특정 좌표의 블럭 주소 반환
    Block* XY(int x, int y);

    /// @brief 그림자 표시 모드를 지정하는 메서드
    void shadowSwitch();

};


#endif //CSED232_BOARD_H
