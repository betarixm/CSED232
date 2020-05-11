#include "IO.h"
#include <cstdlib>
#include <cstdio>
#include <mutex>
#include "Stack.h"

using namespace std;

void input(Stack<char>& inputStack, mutex& m) {
    char input;

    while(1) {
        system("stty cbreak -echo");
        input = getchar();
        m.lock();
        inputStack.push(input);
        m.unlock();
        system("stty cooked");
    }

}