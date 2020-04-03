#include <iostream>
#include <vector>

int recorder_max(std::vector<int> &student_v); // 리코더를 가져갈 최대 학생 수를 구하는 함수.

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main(){
    using namespace std;
    int student_num = 0, lost = 0, extra = 0, result = 0; // 차례대로 학생 수, 도난 당한 학생 수, 여분 리코더가 있는 학생 수, 결과 값을 담는 변수이다.
    int idx = 0; // 입력을 받기 위한 임시변수이다.
    cin >> student_num >> lost >> extra; // 변수에 값을 입력한다.
    vector<int> student_v(student_num, 0); // 전체 학생 수 크기의 벡터를 선언하고 0으로 초기화한다.

    while(lost-- && cin >> idx){ // 리코더를 도난 당한 학생 번호들을 입력받는다.
        student_v[idx - 1]--; // 도난당한 학생에게서 1을 뺀다.
    }

    while(extra-- && cin >> idx){ // 여분 리코더가 있는 학생 번호들을 입력받는다.
        student_v[idx - 1]++; // 여분의 리코더가 있는 학생에게 1을 더한다.
    }

    result = recorder_max(student_v); // recorder_max를 호출하여 리코더를 가져갈 학생 수를 구한다.

    cout << result; // 결과 값을 출력한다.

    return 0;
}

int recorder_max(std::vector<int>& student_v){ // 리코더를 가져갈 최대 학생 수를 구하는 함수.
    using namespace std;
    int result = 0; // result: 결과 값을 저장하는 변수.

    for(auto iter = student_v.begin(); iter != student_v.end(); iter++) { // 학생 벡터를 순회한다.
        // 학생의 값이 0 이상이면 리코더를 가져갈 학생으로 추가하고 continue 한다.
        if (*iter >= 0 && result++) continue;
        // 도난 당한 학생이 앞 번호 친구에게 빌리면 리코더를 가져갈 학생으로 추가하고 continue 한다.
        if (iter != student_v.begin() && iter[-1] > 0){
            result++;
            continue;
        }
        // 도난 당한 학생이 뒷 번호 친구에게 빌리면 리코더를 가져갈 학생으로 추가하고, 뒷 번호 친구의 값에서 1을 뺀다.
        (iter != student_v.end() && iter[1] > 0) && (result++, iter[1]--);
    }

    return result; // 결과 값을 반환한다.
}