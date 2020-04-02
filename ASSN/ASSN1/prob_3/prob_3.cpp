#include <iostream>
#include <vector>
#define MAX(X, Y) ((X>Y)?(X):(Y))
#define CACHE_INIT -1

using namespace std;

int whiskey_max(const int idx, const vector<int> &whiskey, vector<int> &cache);

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){


    int size = 0, input = 0;
    cin >> size;
    vector<int> whiskey, cache(size, CACHE_INIT);

    while(size-- && cin >> input){
        whiskey.push_back(input);
    }

    cout << whiskey_max(0, whiskey, cache);
    return 0;

}

int whiskey_max(const int idx, const vector<int> &whiskey, vector<int> &cache){
    using namespace std;
    int case_list[3] = {0, }, partial_max = 0, partial_length = MAX((int) whiskey.size() - idx, 0);

    if(!(0 <= idx && idx < cache.size())) return 0;

    if(cache[idx] == CACHE_INIT){
        if(partial_length <= 2){
            while(partial_length >= 0 && partial_length--){
                partial_max += whiskey[whiskey.size() - 1 - partial_length];
            }
        } else {
            case_list[0] = whiskey_max(idx + 3, whiskey, cache) + whiskey[idx + 0] + whiskey[idx + 1];
            case_list[1] = whiskey_max(idx + 2, whiskey, cache) + whiskey[idx + 0];
            case_list[2] = whiskey_max(idx + 1, whiskey, cache);
            partial_max = MAX(MAX(case_list[0], case_list[1]), case_list[2]);
        }
        cache[idx] = partial_max;
    }

    return cache[idx];
}