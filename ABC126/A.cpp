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
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    S[K-1] = S[K-1] - 'A' + 'a';
    cout << S << endl;

    return 0;
}