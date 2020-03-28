#include <iostream>
#include <vector>
#define MAX(X, Y) ((X>Y)?(X):(Y))
#define CACHE_INIT -1

int whiskey_max(const int idx, const std::vector<int> &whiskey, std::vector<int> &cache);

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){
    using namespace std;

    int size = 0, input = 0, result = 0;
    cin >> size;
    vector<int> whiskey, cache_1(size, CACHE_INIT), cache_2(size, CACHE_INIT);

    while(size-- && cin >> input){
        whiskey.push_back(input);
    }

    result = whiskey_max(0, whiskey, cache_1);
    cout << result;
    return 0;

}

int whiskey_max(const int idx, const std::vector<int> &whiskey, std::vector<int> &cache){
    using namespace std;
    int case_list[3] = {0, }, partial_sum = 0, partial_size = MAX((int) whiskey.size() - idx, 0);
    if(cache[idx] == CACHE_INIT){
        if(partial_size <= 2){
            while(partial_size >= 0 && partial_size--){
                partial_sum += whiskey[whiskey.size() - 1 - partial_size];
            }
        } else {
            case_list[0] = whiskey_max(idx + 3, whiskey, cache) + whiskey[idx + 0] + whiskey[idx + 1];
            case_list[1] = whiskey_max(idx + 2, whiskey, cache) + whiskey[idx + 0];
            case_list[2] = whiskey_max(idx + 1, whiskey, cache);
            partial_sum = MAX(MAX(case_list[0], case_list[1]), case_list[2]);
        }
        cache[idx] = partial_sum;
    }

    return (0 <= idx && idx < cache.size())?(cache[idx]):(0);
}