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

ull gcd(ull X, ull Y) {
    if(Y==0)
        return X;

    if(X < Y)
        return gcd(Y, X);

    return gcd(Y, X%Y);
}

ull count(ull A, ull B, ull X) {
    if(B < X)
        return 0;
    
    return max(ull(0), B / X - (A-1) / X);
}

int main() {
    ull A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << B-A+1 - count(A,B,C) - count(A,B,D) + count(A,B,C*D/gcd(C,D)) << endl;
    return 0;
}