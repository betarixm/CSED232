#include <iostream>

using namespace std;

void wow(int& a){
    cout << a;
}


int main(){
    using namespace std;
    int b = 1;

    wow(b);

    return 0;
}