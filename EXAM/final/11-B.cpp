#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main() {
    using namespace std;

    vector<int> data{11, 17, 4, 10, 29, 4, 18, 18};

    int upper_bound = 20;
    int lower_bound = 10;

    /// Answer /////////////////////
    std::transform(data.begin(), data.end(), data.begin(),[&](int n)->int {
        if(n > upper_bound) { return upper_bound; }
        else if(n < lower_bound) { return lower_bound; }
        return n;
    });
    ////////////////////////////////

    for(auto x: data) cout << x << " ";
    cout << endl;

    return 0;
}