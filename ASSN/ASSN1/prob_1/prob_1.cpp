#include <iostream>

int gcd(int w, int h);

int main(){
    using namespace std;

    int w = 0, h = 0;

    cin >> w >> h;
    cout << (w * h) - (w + h - gcd(w,h));

    return 0;
}

int gcd(int w, int h){
    return (h == 0)?(w):(gcd(h, w%h));
}