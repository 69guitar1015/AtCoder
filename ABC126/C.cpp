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
    double N, K;
    cin >> N >> K;

    double prob = 1.0/N * (N - min(N, K-1));
    for(int i=1; i<=min(N, K-1); i++) {
        auto n = ceil(log2(K/i));
        prob += 1.0/N * pow(1.0/2, n);
    }
    printf("%.16f\n", prob);
    return 0;
}