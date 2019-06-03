#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ull> S(N), T(N), X(N);
    for(int i=0; i<N; i++)
        cin >> S[i] >> T[i] >> X[i];

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&X](size_t i1, size_t i2) {
        return X[i1] < X[i2];
    });

    vector<ull> D(Q);
    for(int i=0; i<Q; i++)
        cin >> D[i];

    for(int i=0; i<Q; i++) {
        int ans = -1;
        for(int j=0; j<N; j++) {
            int k = idx[j];
            auto s = 1.0*(S[k]-0.5-D[i])/X[k];
            if(s > 1.0)
                continue;

            auto e = 1.0*(T[k]-0.5-D[i])/X[k];
            if(e < 1.0)
                continue;

            ans = X[k];
            break;
        }
        cout << ans << endl;
    }
    

    return 0;
}