#include <iostream>

int gcd(int a, int b); // 최대공약수를 구하는 함수

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){
    using namespace std; // std 사용.

    int w = 0, h = 0; // w: 모눈 종이의 가로 길이, h: 모눈종이의 세로 길이

    cin >> w >> h; // 사용자로 부터 모눈종이에 대한 정보를 입력받는다.
    // 총 모눈종이 칸 수로부터 (가로 + 세로 - 가로와 세로의 최대 공약수)를 빼면 온전한 사각형 갯수를 구할 수 있다.
    cout << (w * h) - (w + h - gcd(w,h));  // 온전한 사각형의 개수를 출력한다.

    return 0;
}

int gcd(int a, int b){ // 최대공약수를 구하는 함수.
    return (b == 0) ? (a) : (gcd(b, a % b)); // 재귀적으로 유클리드 호제법을 구현하여 최대공약수를 구한다.
}