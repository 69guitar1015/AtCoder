#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int deg_x10, dis;
    vector<string> directions = vector<string> {
        "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
        "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW",
    };
    cin >> deg_x10 >> dis;

    int idx = (deg_x10 * 10 + 1125) % 36000 / 2250;
    string dir = directions[idx];
    
    int speed_x10 = round(10.0 * dis / 60);
    int wind_power = 0;
    int steps[12] = {3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327};
    for (auto s : steps) {
        if (speed_x10 < s) {break;}
        wind_power++;
    }

    if (wind_power == 0){
        dir = "C";
    }
    
    cout << dir << " " << wind_power << endl;

    return 0;
}