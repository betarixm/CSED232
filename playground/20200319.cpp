#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;



int main(){
    int a = 0, b = -1;

    if((a--, b++)){
        cout << "T";
    }
}