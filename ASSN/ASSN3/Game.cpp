#include "Game.h"

#include <iostream>
#include "Tetromino.h"
#include "Queue.h"
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

/**
 * @brief 테트리미노의 사용 여부 배열을 초기화 하는 메서드
 */
void Game::initUsedArray() {
    // 모든 값을 거짓으로 초기화
    for(auto& i: isUsed){
        i = false;
    }
}

/**
 * @brief 테트리미노가 모두 사용되었는지 여부를 반환하는 메서드
 * @return 테트리미노 1세트 사용 여부
 */
bool Game::isAllUsed() {
    // 모든 값이 참일 경우 참 반환
    for(auto& i : isUsed){
        if(!i) return false;
    }
    return true;
}

/**
 * @brief 사용되지 않은 테트리미노를 만들어주는 메서드
 * @return 새로운 테트리미노
 */
Tetromino *Game::getTetromino() {
    int num;

    // 사용되지 않은 테트리미노의 번호를 가져온다.
    do {
        if(isAllUsed()){ initUsedArray(); }
        num = rand() % NUM_TETROMINO;
    } while(isUsed[num]);

    // 사용된 테트리미노임을 마킹한다.
    isUsed[num] = true;

    // 테트리미노 생성 주소를 담을 변수
    Tetromino* result;

    // 테트리미노의 종류에 따라서 적절히 테트리미노의 자식 클래스를 할당한다.
    switch(num){
        case MINO_I:
            result = new Mino_I(COL / 2, ROW, *blockList, board);
            break;
        case MINO_O:
            result = new Mino_O(COL / 2, ROW + 1, *blockList, board);
            break;
        case MINO_T:
            result = new Mino_T(COL / 2, ROW, *blockList, board);
            break;
        case MINO_L:
            result = new Mino_L(COL / 2, ROW, *blockList, board);
            break;
        case MINO_J:
            result = new Mino_J(COL / 2, ROW, *blockList, board);
            break;
        case MINO_S:
            result = new Mino_S(COL / 2, ROW, *blockList, board);
            break;
        case MINO_Z:
            result = new Mino_Z(COL / 2, ROW, *blockList, board);
            break;
        default:
            result = nullptr;
            break;
    }

    // 테트리미노를 스택에 저장한다. (동적 할당 해제용)
    minoStack.push(result);
    return result;

}

/**
 * @brief 현재 테트리미노와 다음 테트리미노를 세팅하는 메서드
 */
void Game::setTetromino() {

    t = next_t; // 현재 테트리미노 설정
    next_t = getTetromino(); // 다음 테트리미노 설정
}

/**
 * @brief 입력 값을 가져오는 메서드
 * @return 입력 값
 */
char Game::getInput() {
    char tmp = 0; // 사용자의 입력 값을 저장할 변수
    m->lock(); // 뮤텍스 락
    // 스레드 공유 인풋 큐로부터 결과를 가져온다.
    bool res = inputQueue->pop(tmp);
    m->unlock(); // 뮤텍스 언락

    if(res){
        // 쿼리에 성공하면 값을 반환한다.
        return tmp;
    } else {
        // 실패했을 경우 -1을 반환한다.
        return -1;
    }
}

/**
 * @brief 입력을 파싱하는 메서드
 * @return 정상적인 입력 여부
 */
bool Game::parseInput() {
    char input = getInput(); // 입력 값을 가져온다
    if(input == 'a'){
        // 왼쪽으로 한칸 이동
        t->move(-1, 0, false);
    } else if (input == 'd') {
        // 오른쪽으로 한 칸 이동
        t->move(1, 0, false);
    } else if (input == 's') {
        // 아래로 한 칸 이동
        t->move(0, -1, false);
    } else if (input == 'w') {
        // 시계 방향 회전
        t->rotate(CW);
    } else if (input == 'x') {
        // 반시계 방향 회전
        t->rotate(CCW);
    } else if (input == 'm') {
        // 그림자 여부 변경
        board->shadowSwitch();
    } else if (input == ' ') {
        // 하드 드랍
        t->hardDrop();
    } else {
        return false; // 비정상임을 반환
    }

    return true; // 정상이었음을 반환
}

/**
 * @brief 점수를 계산하는 메서드
 * @param num_lines 삭제된 줄 수
 */
void Game::checkScore(int num_lines) {
    int partial_score = 0; // 추가될 점수
    /*
     * 1줄:  100점
     * 2줄:  300점
     * 3줄:  500점
     * 4줄: 1000점
     */

    if(num_lines == 0){
        // 테트리미노가 정지되었는데, 지운 줄 수가 0이라면 콤보를 0으로 지정한다.
        if(combo > 0 && t->isStop()) combo = 0;
        return;
    } else if(num_lines == 1) {
        partial_score = 100;
    } else if(num_lines == 2) {
        partial_score = 300;
    } else if (num_lines == 3) {
        partial_score = 500;
    } else if (num_lines >= 4) {
        partial_score = 1000;
    }

    combo++; // 콤보 증가

    if(combo >= 2){ // 콤보가 2 이상일 경우 추가 점수를 부여한다.
        partial_score += 100 * (combo - 1);
    }

    score += partial_score; // 추가될 점수를 지정한다.
    coefficient = 1 + ((int)(score/1000))/10; // 점수에 따른 속도 계수를 지정한다.
}

/**
 * @brief Game 클래스 생성자
 * @param _blockList 이 클래스에서 사용할 블록 리스트 오브젝트
 * @param _board 이 클래스에서 사용할 보드 클래스 오브젝트
 * @param _inputQueue 이 클래스에서 사용할 공유 인풋 큐
 * @param _m
 */
Game::Game(BlockList *_blockList, Board *_board, Queue<char> *_inputQueue, mutex *_m) {
    blockList = _blockList;
    board = _board;
    inputQueue = _inputQueue;
    m = _m;
    t = nullptr;
    next_t = getTetromino();
    setTetromino();
}

/**
 * @brief 게임을 실행하는 메서드
 * @return 게임 점수
 */
int Game::run() {
    while(++gameProcess, ++inputProcess){ // 기본 시간 단위인 프로세스를 증가시킨다
        if(inputProcess % inputTick == 0){ // 인풋 틱마다 유저의 인풋을 받는다
            if(parseInput()){ // 인풋 결과가 있다면 렌더링 진행
                board->render(t, next_t, score, combo);
            }
            inputProcess = 0;
        }

        if(gameProcess % (int)(unitTick / coefficient) == 0){ // 게임 틱마다 판정을 진행한다.
            t->onTick(); // 테트리미노의 틱 이벤트 실행
            checkScore(blockList->removeLines()); // 줄을 삭제하고, 점수를 계산한다.
            board->render(t, next_t, score, combo); // 게임을 렌더링한다.
            // 게임 오버일 경우 점수를 리턴한다.
            if(blockList->isGameOver()){
                return score;
            }
            gameProcess = 0;
            // 테트리미노가 바닥에 다다랐다면 새로운 테트리미노를 지정
            if(t->isStop()){
                setTetromino();
            }
        }
    }
    return 0;
}
/**
 * @brief 로그를 남길 것인지 확인하는 메서드
 * @return 로그 남김 여부
 */
bool Game::checkSaveLog() {
    char input;
    while(true){ // y나 n이 입력으로 들어올 때 까지 반복
        flush(cout);
        cin.clear();
        // 현재 터미널 설정에서 정상적으로 출력하기 위해 시스템을 이용하였다.
        system("echo \"Do you want to save your score? [PRESS (y/n)]\"");
        // 공유 인풋 큐에서 입력을 가져온다.
        getChar(*inputQueue, input, *m);
        // 입력을 출
        cout << input << endl;

        if(input == 'y') {
            // 입력이 y 라면 로그를 남기고 true를 반환
            logScore(score);
            return true;
        } else if (input == 'n') {
            // 입력이 n 이라면 false를 반환
            return false;
        } else {
            // 그 외의 경우 입력 재시도
            cout << "Please input 'y' or 'n'" << endl;
        }
        cout << endl;
    }
}
/**
 * @brief 재시작 여부를 체크하는 메서드
 * @return 재시작 여부
 */
bool Game::checkRestart() {
    char input;
    while(true){ // 정상적인 입력이 들어올 때 까지 반복
        flush(cout);
        cin.clear();
        // 현재 터미널 설정에서 정상적으로 출력하기 위해 시스템을 이용하였다.
        system("echo \"Do you want to restart? [PRESS (y/n)]\"");
        // 공유 인풋 큐로부터 값 조회
        getChar(*inputQueue, input, *m);
        // 입력 값 출력
        cout << input << endl;
        if(input == 'y'){
            // y일 경우 true 반환
            return true;
        } else if (input == 'n'){
            // n일 경우 false 반환
            return false;
        } else { // 그 외일 경우 재시도
            cout << "Please press 'y' or 'n'" << endl;
        }
        cout << endl;
    }
}

/**
 * @brief Game 클래스 소멸자
 */
Game::~Game() {
    Tetromino* tmp = nullptr;
    // 게임에 사용된 테트리미노들을 할당 해제한다.
    while(minoStack.pop(tmp)){
        delete(tmp);
    }
}
