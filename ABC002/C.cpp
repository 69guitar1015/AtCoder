#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc;

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto ans = abs((xa-xc) * (yb-yc) - (ya-yc) * (xb-xc)) / 2;
    printf("%f\n", ans);
    
    return 0;
}