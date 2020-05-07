// main.cpp
#include <iostream>
#include "polar.h"
#include "polar_ops.h"
using namespace std;
int main() {
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        cout << "polar: " << pplace.distance << ", " << pplace.angle << endl;
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n"; return 0;
}