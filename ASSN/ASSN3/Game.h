#ifndef CSED232_GAME_H
#define CSED232_GAME_H

#include <mutex>
#include <iostream>
#include <random>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "Stack.h"
#include "Tetromino.h"
#include "const.h"
#include "Queue.h"
#include "IO.h"
#define NUM_TETROMINO 7

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

using namespace std;

class Game {
private:
    int unitTick = 100000000;
    int inputTick = 100000;
    int score = 0;
    int combo = 0;
    unsigned int gameProcess = 0;
    unsigned int inputProcess = 0;
    bool isUsed[NUM_TETROMINO] {false, };
    double coefficient = 1;

    BlockList* blockList;
    Board* board;
    Queue<char>* inputQueue;
    Stack<Tetromino*> minoStack;
    mutex* m;
    Tetromino* t;
    Tetromino* next_t;

    /// @brief 테트리미노의 사용 여부 배열을 초기화 하는 메서드
    void initUsedArray();

    /// @brief 테트리미노가 모두 사용되었는지 여부를 반환하는 메서드
    bool isAllUsed();

    /// @brief 사용되지 않은 테트리미노를 만들어주는 메서드
    Tetromino* getTetromino();

    /// @brief 현재 테트리미노와 다음 테트리미노를 세팅하는 메서드
    void setTetromino();

    /// @brief 입력 값을 가져오는 메서드
    char getInput();

    /// @brief 입력을 파싱하는 메서드
    bool parseInput();

    /// @brief 점수를 계산하는 메서드
    void checkScore(int num_lines);

public:
    /// @brief Game 클래스 생성자
    Game(BlockList* _blockList, Board* _board, Queue<char> *_inputQueue, mutex* _m);

    /// @brief 게임을 실행하는 메서드
    int run();

    /// @brief 로그를 남길 것인지 확인하는 메서드
    bool checkSaveLog();

    /// @brief 재시작 여부를 체크하는 메서드
    bool checkRestart();
};


#endif //CSED232_GAME_H
