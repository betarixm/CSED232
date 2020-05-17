#ifndef CSED232_GAME_H
#define CSED232_GAME_H


#define NUM_TETROMINO 7

#include <mutex>
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

using namespace std;

class Board;
class BlockList;
class Tetromino;

template<typename T>
class Stack;
template<typename V>
class Queue;

/**
 * @brief 게임의 진행을 관리하는 클래스
 */
class Game {
private:
    int unitTick = 50000000; /// @brief 기본 게임 진행 틱
    int inputTick = 100000; /// @brief 입력 틱
    int score = 0; /// @brief 점수
    int combo = 0; /// @brief 콤보
    unsigned int gameProcess = 0; /// @brief 게임 진행 틱 카운터
    unsigned int inputProcess = 0; /// @brief 유저 인풋 틱 카운터
    bool isUsed[NUM_TETROMINO] {false, }; /// @brief 테트리미노 사용 여부를 저장하는 배열
    double coefficient = 1; /// @brief 게임 속도 배수

    BlockList* blockList; /// @brief 게임에서 사용할 블럭리스트 오브젝트의 주소
    Board* board; /// @brief 게임에서 사용할 보드 오브젝트의 주소
    Queue<char>* inputQueue; /// @brief 공유 인풋 큐 주소
    Stack<Tetromino*> minoStack; /// @brief 사용한 테트리미노 스택
    mutex* m; /// @brief 스레드 뮤텍스 주소
    Tetromino* t; /// @brief 현재 게임 중인 테트리미노
    Tetromino* next_t; /// @brief 다음 테트리미노

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

    /// @brief Game 클래스 소멸자
    ~Game();
};


#endif //CSED232_GAME_H
