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
    int N, M;
    cin >> N >> M;

    int l=0, r=N;
    for(int i=0; i<M; i++) {
        int Li, Ri;
        cin >> Li >> Ri;
        l = max(l, Li);
        r = min(r, Ri);
    }

    cout << max(0, r - l + 1) << endl;

    return 0;
}