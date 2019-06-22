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
    int N, L;
    cin >> N >> L;

    vector<int> a(N);
    for(int i=0; i<N; i++)
        a[i] = L + i;

    int min_val=99999, min_idx=0;
    for(int i=0; i<N; i++) {
        if(min_val > abs(a[i])) {
            min_idx = i;
            min_val = abs(a[i]);
        }
    }
            

    cout << accumulate(a.begin(), a.end(), 0) - a[min_idx] << endl;

    return 0;
}