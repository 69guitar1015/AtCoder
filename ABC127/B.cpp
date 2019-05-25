#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int r, D, x;
    cin >> r >> D >> x;

    for(int i=0; i<10; i++) {
        x = r*x - D;
        cout << x << endl;
    }

    return 0;
}