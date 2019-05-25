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

bool compare_by_second(pair<int, ull> a, pair<int, ull> b) {
    return a.second > b.second;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<ull> A(N);
    vector<pair<int, ull>> BC(M);    
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<M; i++) {
        ull b, c;
        cin >> b >> c;
        BC[i] = pair<int, ull>(b, c);
    }
    sort(A.begin(), A.end());
    sort(BC.begin(), BC.end(), compare_by_second);

    bool exit = false;
    int i = 0;
    for(int j=0; j<M && (!exit); j++) {
        int B = BC[j].first;
        ull C = BC[j].second;
        for(int k=0; k<B && (!exit); k++) {
            if(A[i] >= C)
                exit = true;
            else
                A[i] = C;
            i++;
        }
    }

    ull sum = 0;
    for(int i=0; i<N; i++)
        sum += A[i];
    cout << sum << endl;

    return 0;
}