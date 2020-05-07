#include <iostream>
using namespace std;

void func() {
    std::cout << "Hello" << std::endl;
}

namespace MyNameSpace {
    void func()
    {
        std::cout << "Bye~" << std::endl;
    }

    void func2()
    {
        ::func(); // (a)
    }
}

int main(){
    MyNameSpace::func2();
}