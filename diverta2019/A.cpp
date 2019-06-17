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
    int N, K;
    cin >> N >> K;

    if(K==1)
        cout << 0 << endl;
    else
        cout << N - K << endl;
    
    return 0;
}