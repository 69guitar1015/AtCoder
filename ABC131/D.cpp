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
    int N;
    cin >> N;

    vector<pair<ull,ull>> BA(N);
    for(int i=0; i<N; i++) {
        cin >> BA[i].second >> BA[i].first;
    }
    sort(BA.begin(), BA.end());

    ull cum = 0;
    for(int i=0; i<N; i++) {
        cum += BA[i].second;
        if(i<N-1 && BA[i].first==BA[i+1].first) 
            continue;

        if(BA[i].first < cum) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}