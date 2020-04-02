#include <iostream>
#include <vector>

using namespace std;

int recorder_max(vector<int> &students); // greedy하게 리코더를 가져갈 수 있는 최대의 학생 수를 구하는 함수

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){
    int student_num = 0, loss_num = 0, extra_num = 0, result_num = 0; // 학생 수 정보들을 담을 변수들 선언
    int idx = 0; // 인덱스를 위한 임시 변수.
    cin >> student_num >> loss_num >> extra_num; // 학생 수 정보들을 입력받는다.
    vector<int> students(student_num, 0); // 전체 학생 수 크기의 벡터를 선언하고 0으로 초기화한다.

    while(loss_num-- && cin >> idx){ // 잃어버린 학생 수 만큼 반복
        students[idx-1]--; // 학생 벡터에서 잃어버린 학생 번호를 참조하여 1을 뺀다.
    }

    while(extra_num-- && cin >> idx){ // 여분이 있는 학생 수 만큼 반복
        students[idx-1]++; // 학생 벡터에서 여분이 있는 학생 번호를 참조하여 1을 더한다.
    }

    result_num = recorder_max(students); // 리코더를 가져갈 수 있는 최대 학생 수를 구하는 함수 recorder_max 호출.

    cout << result_num; // 최대 값 출력

    return 0;
}

int recorder_max(vector<int>& students){ // greedy하게 리코더를 가져갈 수 있는 최대의 학생 수를 구하는 함수
    int idx = 0, result_num = 0; // 인덱스 임시 변수와 결과값을 담을 변수 선언.
    for(idx = 0; idx < students.size(); idx++){ // 학생 벡터 iterate.
        if(students[idx] < 0) { // 어떤 학생의 값이 0보다 작다면, 즉 리코더를 도난당했다면,
            if (idx >= 1 && students[idx - 1] > 0) { // 그런데 앞 번호 친구에게 여분의 리코더가 있다면,
                students[idx - 1]--; // 여분의 리코더를
                students[idx]++; // 도난 당한 친구에게 대여
            } else if (idx <= students.size() && students[idx + 1] > 0) { // 앞 번호 친구에게는 없고, 뒷번호 친구에게 있다면,
                students[idx + 1]--; // 여분의 리코더를
                students[idx]++; // 도난 당한 친구에게 대여
            }
        }
        result_num += (students[idx] >= 0); // 모든 대여 과정이 종료된 후, 학생의 값이 0 이상이라면 리코더를 가져갈 수 있는 학생으로 추가한다.
    }

    return result_num; // 결과 값 반환.
}