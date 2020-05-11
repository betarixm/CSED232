#ifndef CSED232_IO_H
#define CSED232_IO_H

#include "Stack.h"
#include <mutex>

void input(Stack<char>& inputStack, std::mutex& m);


#endif //CSED232_IO_H
