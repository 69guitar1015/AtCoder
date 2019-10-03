#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int M, D;
    cin >> M >> D;

    int count = 0;
    for(int m=1; m<=M; m++) {
        for(int d=1; d<=D; d++) {
            int d1 = (d%10);
            int d10 = (d/10);
            if(d1 >= 2 && d10 >= 2 && d1*d10==m)
                count++;
        }
    }

    cout << count << endl;

    return 0;
}