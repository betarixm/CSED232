# include <iostream>

template<int N>
struct Factorial {
    enum { value = N * Factorial<N-1>::value };
};

// Answer
template<>
struct Factorial<0> {
    enum { value = 1 };
};
//

int main()
{
    using namespace std;

    int a = Factorial<5>::value;
    cout << a << endl;
    return 0;
}