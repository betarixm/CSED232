#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "BlockList.h"
#include "Board.h"
#include "Queue.h"
#include "IO.h"
#include "Game.h"

using namespace std;

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

int main(){
    showTitle(); // "TETRIS" 타이틀 노출

    system("stty cbreak -icanon -echo"); // 입력의 화면 표시를 중단시키고, 터미널로부터 입력을 RAW하게 받아옴.

    Queue<char> inputQueue; // 다른 스레드와 공유하는 인풋 큐.
    mutex m; // 다른 스레드와 리소스를 공유할 때, 데드락에 걸리지 않기 위해 뮤텍스 락을 이용.
    bool isNotPause = true; // 인풋 스레드의 일시정지 여부 지정
    bool isRun = true; // 인풋 스레드의 실행 여부 지정

    thread thInput(input, ref(inputQueue), ref(m), ref(isNotPause), ref(isRun)); // 인풋 스레드 호출

    srand((unsigned int)time(nullptr)); // 랜덤 초기화
    while(true){
        showLoading(); // 로딩 텍스트 노출

        BlockList blockList; // 생성된 블록들을 담는 곳
        Board board(blockList); // 게임 블럭들의 출력을 담당.
        Game game(&blockList, &board, &inputQueue, &m); // 게임의 주 진행을 담당.

        game.run(); // 게임 시작

        // 게임 종료 시,
        showGameOver(); // 게임 오버 텍스트 노출.
        bool isSaveLog = game.checkSaveLog(); // 로그 저장 여부 메뉴
        bool isRestart = game.checkRestart(); // 재시작 여부 메뉴
        flush(cout); // 출력 클리어
        cin.clear(); // 입력 클리어
        if(!isRestart){ break; } // 재시작하는 경우가 아니라면 반복문 탈출 (종료)
    }

    // thThread와 통신.
    m.lock();
    isRun = false; // thThread 종료 시그널 전송.
    m.unlock();

    thInput.detach(); // 인풋 스레드 detach.

    cout << "Press Any Key to Exit..." << endl; // stty sane 한 후 getchar()를 대기하기 때문에 안내문 표시.
    system("stty sane"); // 터미널 설정 원래대로 복귀

    return 0;
}

