#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main(){
    int a = 1;
    int* test[5] = {&a, &a, &a, &a, &a};
    *(test[1]) = 1;

    for(auto& i : test){
        i = nullptr;
    }

    for(auto&i : test){
        if (i == nullptr){
            cout << "wow";
        }
    }

}