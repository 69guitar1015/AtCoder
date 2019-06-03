#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int search(int N, int M, vector<vector<int>> &s, vector<int> &p) {
    int count = 0;

    for(int i=0; i<pow(2, N); i++) {
        bitset<10> b(i);
        vector<int> q(M);
        for(int j=0; j<N; j++) {
            if(b[j]==1) {
                for(int k=0; k<M; k++) {
                    q[k] += s[k][j];
                }
            }
        }

        bool f = true;
        for(int j=0; j<M; j++) {
            f = f && ((p[j]+q[j]) % 2 == 0);
        }

        if(f)
            count++;
    }

    return count;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> s(M);
    for(int i=0; i<M; i++) {
        int k;
        cin >> k;
        s[i] = vector<int>(N);
        for(int j=0; j<k; j++) {
            int si;
            cin >> si;
            s[i][si-1] = 1;
        }
    }

    vector<int> p(M);
    for(int i=0; i<M; i++)
        cin >> p[i];


    auto count = search(N, M, s, p);

    cout << count << endl;

    return 0;
}