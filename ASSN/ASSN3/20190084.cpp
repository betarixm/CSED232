#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Block.h"
#include "BlockList.h"
#include "Board.h"
#include "const.h"
#include "Tetromino.h"
#include "Stack.h"
#include "Queue.h"
#include "IO.h"
#include "Game.h"

using namespace std;

int main(){
    showTitle();
    system("stty cbreak -icanon -echo");
    Queue<char> inputQueue;
    mutex m;
    bool isNotPause = true;
    bool isRun = true;
    thread thInput(input, ref(inputQueue), ref(m), ref(isNotPause), ref(isRun));

    srand((unsigned int)time(nullptr));
    while(true){
        showLoading();
        BlockList blockList;
        Board board(blockList);
        Game game(&blockList, &board, &inputQueue, &m);

        game.run();

        // flush(cout);
        // cin.clear();
        // cin.ignore();
        showGameOver();
        bool isSaveLog = game.checkSaveLog();
        bool isRestart = game.checkRestart();
        flush(cout);
        cin.clear();
        if(!isRestart){ break; }
    }

    m.lock();
    isRun = false;
    m.unlock();
    thInput.detach();
    cout << "Press Any Key to Exit..." << endl;
    system("stty sane");

    return 0;
}

