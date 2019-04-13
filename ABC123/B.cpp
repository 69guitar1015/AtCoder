#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> dishes(5);
    for(auto& d : dishes)
        cin >> d;

    sort(dishes.begin(), dishes.end(), [](int x, int y) -> int {
        return (x+9)%10 > (y+9)%10;
    });

    int total_time = 0;

    for(auto d=dishes.begin(); d != dishes.end()-1; d++)
        total_time += *d + 9 - (*d+9)%10;
    total_time += *(dishes.end()-1);
    cout << total_time << endl;

    return 0;
}