#include "Board.h"

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

/**
 * @brief 게임 보드를 초기화 하는 메서드
 */
void Board::initGameBoard() {
    // 보드 배열을 탐색하면서
    for(auto& i : gameBoard){
        for(auto& j: i){
            // nullptr으로 채운다.
            j = nullptr;
        }
    }
}

/**
 * @brief 줄을 출력하는 메서드
 * @param isEndl 줄 바꿈 여부
 * @param num 출력할 줄의 길이
 */
void Board::printLine(bool isEndl, int num) {
    // 줄의 길이만큼 구분자 (SEPerator)를 출력한다.
    for(int i=0; i < num; i++){
        cout << SEP;
    }
    // 줄을 바꿔야 할 경우 endl 출력.
    if(isEndl) cout << endl;
}

/**
 * @brief 보드 클래스 생성자
 * @param list 이 보드가 사용할 BlockList 오브젝트
 */
Board::Board(BlockList &list) {
    this->blockList = &list; // 블록 리스트 오브젝트 지정
    this->shadow = nullptr; // 그림자 테트리미노 초기화

    // 게임보드 nulllptr으로 초기화
    initGameBoard();

    // 정보 보드 공백으로 초기화
    initInfoBoard();

}

/**
 * @brief 보드 배열을 출력하기 위해 세팅하는 메서드
 */
void Board::setGameBoard() {
    initGameBoard(); // 보드 리셋
    // 블록 리스트를 탐색
    for(int i = 0; i < MAX_BLOCK; i++){
        auto tmp = blockList->at(i);
        if(tmp != nullptr){ // 블록을 발견 했다면
            int y = CONVERT_Y(tmp->y()); // y 좌표 변환
            // 좌표가 보드 안의 좌표라면 게임 보드에 지정한다.
            if((0 <= y && y < ROW) && (0 <= tmp->x() && tmp->x() < COL)){
                // 그림자보다는 블록이 우선되서 지정된다.
                auto boardPoint = gameBoard[y][tmp->x()];
                if((boardPoint == nullptr) || boardPoint->isShadow())
                    gameBoard[y][tmp->x()] = tmp;
            }
        }
    }
}

/**
 * @brief 게임을 렌더링하는 메서드
 * @param currentMino 현재 테트리미노의 주소
 * @param nextMino 다음 테트리미노의 주소
 * @param score 현재 점수
 * @param combo 콤보 수
 */
void Board::render(Tetromino *currentMino, Tetromino *nextMino, int score, int combo) {
    makeShadow(currentMino); // 그림자를 생성한다.

    setInfoBoard(nextMino, score, combo); // 정보 보드를 초기화한다.

    this->setGameBoard(); // 게임보드를 초기화한다.

    clear(); // 출력 클리어

    // 구분 줄 출력
    printLine(true, COL + INFO_COL + 3);
    int row = 0; // 현재 줄 수 카운터
    for(auto& i : gameBoard){ // 게임 보드 ROW 탐색

        // 게임 보드 렌더링
        cout << SEP; // 구분자 출력
        for(auto& j: i){ // 게임 보드 COL 탐색
            // 블럭들 출력
            if(j == nullptr){
                cout << " ";
            } else {
                j->show();
            }
        }
        cout << SEP; // 구분자 출력

        // 정보 보드 렌더링
        if(row < INFO_ROW){ // 정보 보드의 최대 높이보다 작을 경우에만 렌더링
            for(auto&k : infoBoard[row]){
                cout << k;
            }
            cout << SEP; // 구분자 출력
        }

        // 정보 보드의 마지막에 구분선 출력
        if(row == INFO_ROW){
            printLine(false, INFO_COL + 1);
        }

        cout << endl;
        row++; // 줄 카운터 증가
    }

    // 구분선 출력
    printLine(true, COL + 2);
    deleteShadow(); // 그림자 삭제
}

/**
 * @brief 정보 보드를 출력하기 위해 세팅하는 메서드
 * @param nextMino 다음 테트리미노의 주소
 * @param score 점수
 * @param combo 콤보
 */
void Board::setInfoBoard(Tetromino *nextMino, int score, int combo) {
    Position axis(INFO_COL / 2 , 2); // 다음 테트리미노 출력 축 지정

    // 출력할 텍스트 배열
    string info_text[4] = {
            " Score",
            " " + to_string(score),
            " Combo",
            " " + to_string(combo)
    };

    initInfoBoard(); // 정보 보드 초기화

    // 다음 테트리미노 세팅
    for(int i = 0; i < 4; i++){
        Block& tmp = nextMino->getBlockByIdx(i);
        infoBoard[axis.y() - tmp.rel_y()][axis.x() + tmp.rel_x()] = tmp.toString();
    }

    // 구분선 세팅
    for(int i = 0; i < INFO_COL; i++){
        infoBoard[INFO_ROW / 3 * 1][i] = SEP;
        infoBoard[INFO_ROW / 3 * 2][i] = SEP;
    }

    // 출력 텍스트 세팅
    for(int i = 0; i < 4; i++){
        int tmp_idx = 0;
        // 현재 채울 칸 지정
        int process = (i < 2)?(1):(2);
        // 구분선 사이에 넣기 위한 규칙 안에서 세팅
        for(auto& l: infoBoard[INFO_ROW / 3 * process + 2 + i % 2]){
            // 출력할 스트링의 길이만큼 한칸씩 지정
            l = info_text[i][tmp_idx++];
            if(tmp_idx == info_text[i].length()) break;
        }
    }

}

/**
 * @brief 정보 보드 배열 초기화
 */
void Board::initInfoBoard(){
    // 정보 보드 배열을 공백으로 초기화한다.
    for(auto&i:infoBoard){
        for(auto&j:i){
            j = " ";
        }
    }
}

/**
 * @brief 특정 좌표의 블럭 주소 반환
 * @param x x 좌표
 * @param y y 좌표
 * @return 해당 좌표의 블럭 주소
 */
Block *Board::XY(int x, int y) {
    // x, y 좌표가 범위 안에 있다면
    if((0 <= x && x < COL) && (0 <= y && y < ROW)){
        // 블럭 주소 반환
        return (gameBoard[ROW - y - 1][x]);
    } else {
        // 없다면 nullptr 반환
        return nullptr;
    }
}

/**
 * @brief 그림자 표시 모드를 지정하는 메서드
 */
void Board::shadowSwitch(){
    // 그림자 표시 모드를 반전시킨다.
    this->isShadowOn = !isShadowOn;
}

/**
 * @brief 그림자를 만드는 메서드
 * @param currentMino
 */
void Board::makeShadow(Tetromino* currentMino) {
    if(!isShadowOn){ // 그림자가 꺼진 상태라면 종료한다.
        return;
    }

    // 그림자 문자열 지정
    string targetStr = "□";

    // 그림자 테트리미노를 지정한다.
    shadow = new Tetromino(*blockList, this);

    // 현재 테트리미노의 정보를 복사한다.
    *shadow = *currentMino;

    // 그림자 블럭으로 세팅
    shadow->setShadowMino(true);
    shadow->setStr(targetStr);

    // 그림자 테트리미노 하드 드롭
    shadow->hardDrop();
}

/**
 * @brief 그림자를 삭제하는 메서드
 */
void Board::deleteShadow(){
    if(!isShadowOn){ // 그림자가 켜진 상태가 아니라면 종료
        return;
    }
    // 그림자 테트리미노 지정 해제
    delete shadow;
    // 블록 리스트에서 그림자 블록 지정 해제
    blockList->removeShadow();
}