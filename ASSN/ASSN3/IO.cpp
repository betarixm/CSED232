#include "IO.h"
#include <cstdlib>
#include <cstdio>
#include <mutex>
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

/**
 * @brief 사용자로부터 입력을 받는 스레드로 실행될 함수
 * @param inputQueue 공유 인풋 큐
 * @param m 뮤텍스
 * @param isNotPause 일시정지 여부
 * @param isRun 실행 여부
 */
void input(Queue<char> &inputQueue, mutex &m, bool &isNotPause, bool &isRun) {
    char input;
    // fd_set rfds;
    // FD_ZERO(&rfds);
    // FD_SET(0, &rfds);

    while(true) {
        m.lock(); // 뮤텍스 락
        if(!isNotPause){
            // 일시정지일 경우 아래의 내용을 실행하지 않는다.
            m.unlock();
            continue;
        }
        if(!isRun){
            // 정지일 경우 종료시킨다.
            m.unlock();
            return;
        }
        m.unlock(); // 뮤텍스 언락
        // while (select(1, &rfds, NULL, NULL, NULL) == 0);

        // 입력을 가져온다.
        if(isNotPause) input = getchar();

        m.lock(); // 뮤텍스 락
        inputQueue.push(input); // 공유 인풋 큐에 입력을 푸시한다.
        m.unlock(); // 뮤텍스 언락
    }
}

/**
 * @brief 로그를 저장하는 함수
 * @param score 점수
 */
void logScore(int score) {
    ifstream in; // 파일 입력 스트림
    ofstream out; // 파일 출력 스트림

    // 파일이 없다면 생성한다.
    out.open("score.txt", ios::app);
    out.close();

    // 파일을 연다
    in.open("score.txt", ios::in);

    // 파일 열기에 실패했을 경우 종료
    if(in.fail()){
        return;
    }

    stringstream buffer; // 로그를 가져올 스트링 버퍼
    // 스트링 버퍼에 현재 파일의 내용을 기입한다.
    buffer << in.rdbuf();
    in.close();
    // 버퍼로 부터 현재 로그 로드
    string log = buffer.str();

    // 현재 점수를 로그의 앞에 더한다.
    log = to_string(score) + "\n" + log;

    // 파일 출력 스트림을 열고 문자열을 기록한다.
    out.open("score.txt", ios::trunc);
    out << log;
    out.close();
}

/**
 * @brief 터미널을 클리어하는 함수
 * @details msys2에서는 system("clear")가 느리게 불리는 경우가 있기 때문에, 다량의 줄을 출력해서 클리어하는 방식을 채택하였다.
 */
void clear(){
    // 20 빈 줄 출력
    for(int i = 0; i < 20; i++){
        cout << endl;
    }
}

/**
 * @brief 공유 인풋 큐에서 입력을 가져오는 함수
 * @param inputQueue 공유 인풋 큐 참조
 * @param result 입력을 저장할 char 참조
 * @param m 뮤텍스
 */
void getChar(Queue<char>& inputQueue, char& result, mutex& m){
    bool isCorrect; // 정상적으로 입력을 가져왔는지 저장하는 변수
    do { // 정상적인 입력이 들어올 때 까지 반복
        m.lock(); // 뮤텍스 락
        isCorrect = inputQueue.pop(result); // 입력값 추출
        m.unlock(); // 뮤텍스 언락
    } while(!isCorrect);
}

/**
 * @brief 게임 타이틀 아스키 아트를 출력하는 함수
 */
void showTitle() {
    cout << endl;
    std::cout << "::::::::::: :::::::::: ::::::::::: :::::::::  ::::::::::: ::::::::  \n" <<
                 "    :+:     :+:            :+:     :+:    :+:     :+:    :+:    :+: \n" <<
                 "    +:+     +:+            +:+     +:+    +:+     +:+    +:+        \n" <<
                 "    +#+     +#++:++#       +#+     +#++:++#:      +#+    +#++:++#++ \n" <<
                 "    +#+     +#+            +#+     +#+    +#+     +#+           +#+ \n" <<
                 "    #+#     #+#            #+#     #+#    #+#     #+#    #+#    #+# \n" <<
                 "    ###     ##########     ###     ###    ### ########### ########  \n";
    cout << endl;
}

/**
 * @brief 게임 오버 아스키 아트를 출력하는 함수
 */
void showGameOver() {
    cout << endl;
    std::cout << " ::::::::      :::     ::::    ::::  :::::::::: \n"  <<
                 ":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:        \n" <<
                 "+:+         +:+   +:+  +:+ +:+:+ +:+ +:+        \n" <<
                 ":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   \n" <<
                 "+#+   +#+# +#+     +#+ +#+       +#+ +#+        \n" <<
                 "#+#    #+# #+#     #+# #+#       #+# #+#        \n" <<
                 " ########  ###     ### ###       ### ########## \n";
    cout << endl;
    std::cout << " ::::::::  :::     ::: :::::::::: :::::::::  \n" <<
                 ":+:    :+: :+:     :+: :+:        :+:    :+: \n" <<
                 "+:+    +:+ +:+     +:+ +:+        +:+    +:+ \n" <<
                 "+#+    +:+ +#+     +:+ +#++:++#   +#++:++#:  \n" <<
                 "+#+    +#+  +#+   +#+  +#+        +#+    +#+ \n" <<
                 "#+#    #+#   #+#+#+#   #+#        #+#    #+# \n" <<
                 " ########      ###     ########## ###    ### \n";
    cout << endl;
}

/**
 * @brief 게임 로딩 아스키 아트를 출력하는 함수
 */
void showLoading() {
    cout << endl;
    std::cout << ":::        ::::::::      :::     ::::::::: ::::::::::: ::::    :::  ::::::::              \n" <<
                 ":+:       :+:    :+:   :+: :+:   :+:    :+:    :+:     :+:+:   :+: :+:    :+:             \n" <<
                 "+:+       +:+    +:+  +:+   +:+  +:+    +:+    +:+     :+:+:+  +:+ +:+                    \n" <<
                 "+#+       +#+    +:+ +#++:++#++: +#+    +:+    +#+     +#+ +:+ +#+ :#:                    \n" <<
                 "+#+       +#+    +#+ +#+     +#+ +#+    +#+    +#+     +#+  +#+#+# +#+   +#+#             \n" <<
                 "#+#       #+#    #+# #+#     #+# #+#    #+#    #+#     #+#   #+#+# #+#    #+# #+# #+# #+# \n" <<
                 "########## ########  ###     ### ######### ########### ###    ####  ########  ### ### ###\n";
    cout << endl;
}
