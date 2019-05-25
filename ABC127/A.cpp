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
    int A, B;
    cin >> A >> B;

    int ans;
    if(A >= 13)
        ans = B;
    else if(A >= 6)
        ans = B / 2;
    else
        ans = 0;

    cout << ans << endl;

    return 0;
}