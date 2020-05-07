#include <iostream>

namespace Namespace1 {
    void func()
    {
        std::cout <<"func()" << std::endl;
    }
    void func(int a)
    {
        std::cout << "func(int)" << std::endl;
    }
    void func(double a)
    {
        std::cout << "func(double)" << std::endl;
    }
}
namespace Namespace2 {
    void func2(int a, int b) { std::cout << "func2(int,int)" << std::endl; }

    using namespace Namespace1; // (a)
}

int main() {
    Namespace2::func();
    Namespace2::func(3);
    Namespace2::func(3.);
    return 0;
}