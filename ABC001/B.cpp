#include <iostream>
using namespace std;

int main() {
    int m, VV;

    cin >> m;

    if(m < 100) {
        VV = 0;
    } else if(m <= 5000) {
        VV = 10 * m / 1000;
    } else if(m <= 30000) {
        VV = 50 + m / 1000;
    } else if(m <= 70000) {
        VV = 80 + (m / 1000 - 30) / 5;
    } else {
        VV = 89;
    }

    printf("%02d\n", VV);

    return 0;
}