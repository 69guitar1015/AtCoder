#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ull N, X;
    cin >> N >> X;

    ull l = N;
    ull a=N-X, b=X;

    while(a!=0) {
        l += 2 * (b/a) * a;
        b = b % a;
        swap(a, b);
    }

    l  -= b;

    cout << l << endl;

    return 0;
}