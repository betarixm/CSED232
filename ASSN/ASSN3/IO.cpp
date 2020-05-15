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

void input(Queue<char> &inputQueue, mutex &m, bool &isNotPause, bool &isRun) {
    char input;
    // fd_set rfds;
    // FD_ZERO(&rfds);
    // FD_SET(0, &rfds);

    while(true) {
        m.lock();
        if(!isNotPause){
            m.unlock();
            continue;
        }
        if(!isRun){
            m.unlock();
            return;
        }
        m.unlock();
        // while (select(1, &rfds, NULL, NULL, NULL) == 0);
        if(isNotPause) input = getchar();
        m.lock();
        inputQueue.push(input);
        m.unlock();
        // system("stty cooked");
    }
}

void getLine(Queue<char> &inputQueue, std::string& result, bool display, mutex& m){
    char tmp;
    int process = 0;
    int inputTick = 100000;
    while(++process){
        if(process % inputTick == 0) {
            inputTick = 0;
        } else {
            continue;
        }
        m.lock();
        bool ioResult = inputQueue.pop(tmp);
        m.unlock();
        if(!ioResult) return;
        if(tmp == '\n'){
            if(display) cout << endl;
            return;
        } else {
            result += tmp;
            if(display) cout << tmp;
        }
    }
}


void logScore(int score) {
    ifstream in;
    ofstream out;

    out.open("score.txt", ios::app);
    out.close();

    in.open("score.txt", ios::in);

    if(in.fail()){
        return;
    }
    stringstream buffer;
    buffer << in.rdbuf();
    in.close();
    string log = buffer.str();

    log = to_string(score) + "\n" + log;

    out.open("score.txt", ios::trunc);
    out << log;
    out.close();
}

void clear(){
    for(int i = 0; i < 20; i++){
        cout << endl;
    }
}

void getChar(Queue<char>& inputQueue, char& result, mutex& m){
    bool isCorrect;
    do {
        m.lock();
        isCorrect = inputQueue.pop(result);
        m.unlock();
    } while(!isCorrect);
}

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
