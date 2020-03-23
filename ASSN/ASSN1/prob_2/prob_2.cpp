#include <iostream>
#include <vector>

int main(){
    using namespace std;

    int student_num = 0, loss_num = 0, extra_num = 0, result_num = 0;
    int idx = 0;
    cin >> student_num >> loss_num >> extra_num;
    vector<int> students(student_num, 0);

    while(loss_num-- && cin >> idx){
        students[idx - 1] -= 1;
    }

    while(extra_num-- && cin >> idx){
        students[idx - 1] += 1;
    }
    for(idx = 0; idx < students.size(); idx++){
        if(students[idx] < 0) {
            if (idx - 1 >= 0 && students[idx - 1] > 0) {
                students[idx - 1] -= 1;
                students[idx] += 1;
            } else if (idx + 1 < students.size() && students[idx + 1] > 0) {
                students[idx + 1] -= 1;
                students[idx] += 1;
            }
        }
        result_num += (students[idx] >= 0);
    }
    cout << result_num;

    return 0;
}