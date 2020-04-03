#include <iostream>
#include <vector>
#define MAX(X, Y) ((X>Y)?(X):(Y)) // 두 수 중 큰 수를 반환하는 매크로
#define CACHE_INIT -1 // 캐시 초기화 값 상수

using namespace std;

int whiskey_max(const int idx, const vector<int> &whiskey, vector<int> &cache); // 최대한 먹을 수 있는 위스키의 양을 반환하는 함수.

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){
    int size = 0, input = 0;
    cin >> size; // 위스키 잔의 개수를 입력받는다.

    vector<int> whiskey, cache(size, CACHE_INIT); // whiskey: 위스키 정보를 담는 벡터. cache: CACHE_INIT으로 초기화 된 메모를 위한 벡터.

    while(size-- && cin >> input){ // 위스키 양들을 입력받는다.
        whiskey.push_back(input);
    }

    cout << whiskey_max(0, whiskey, cache); // whiskey_max를 호출하여 결과 값을 출력한다.
    return 0;

}

int whiskey_max(const int idx, const vector<int> &whiskey, vector<int> &cache){ // 최대한 먹을 수 있는 위스키의 양을 반환하는 함수.
    int case_list[3] = {0, }; // case_list[3]: 3가지 케이스를 저장하는 배열
    int partial_max = 0, partial_length = MAX((int) whiskey.size() - idx, 0); // partial_max: 부분적인 최대 값, partial_length: 현재 주어진 구간의 길이

    if(!(0 <= idx && idx < cache.size())) return 0; // 인덱스가 범위 밖에 있다면 0을 반환한다.

    if(cache[idx] == CACHE_INIT){ // 캐시에 결과 값이 없다면
        if(partial_length <= 2){
            while(partial_length >= 0 && partial_length--){
                partial_max += whiskey[whiskey.size() - 1 - partial_length];
            }
        } else {
            // Notation은 보고서를 참조해주세요.
            // S_n = S_(n+3) + a_n + a_(n+1)
            case_list[0] = whiskey_max(idx + 3, whiskey, cache) + whiskey[idx + 0] + whiskey[idx + 1];
            // S_n = S_(n+2) + a_n
            case_list[1] = whiskey_max(idx + 2, whiskey, cache) + whiskey[idx + 0];
            // S_n = S_(n+1)
            case_list[2] = whiskey_max(idx + 1, whiskey, cache);

            partial_max = MAX(MAX(case_list[0], case_list[1]), case_list[2]); // 셋 중 가장 큰 경우를 고른다.
        }
        cache[idx] = partial_max; // 캐시에 결과를 저장한다.
    }

    return cache[idx]; // 캐시로부터 값을 불러온다.
}