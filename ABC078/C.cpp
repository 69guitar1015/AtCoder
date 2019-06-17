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

    auto one_try = 1900 * M + 100 * (N-M);
    auto p_success = pow(1.0/2, M);

    cout << one_try / p_success << endl;

    return 0;
}