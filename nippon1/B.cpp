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

ull CONST = 1000000007;

int main() {
    ull N, K;
    cin >> N >> K;
    vector<ull> A(N);
    for(ull i=0; i<N; i++)
        cin >> A[i];

    int intra_count = 0;
    for(ull i=0; i<N; i++) {
        for(ull j=0; j<N-1-i; j++) {
            if(A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                intra_count++;
            }
        }
    }

    ull x=A[0], p=0, c=0, rank=1;
    for(ull i=0; i<N; i++) {
        if(x == A[i])
            continue;
        rank++;
        c += (i-p)*(rank-1);
        x = A[i];
        p = i;
    }

    ull total_count = intra_count * K % CONST;

    // /* 

    // inter_count = K * (K-1) / 2 % CONST;
    ull R = 1;
    ull inter_count = 0;
    for(ull i=0; i<R; i++) {
        for(ull j=0; j<R; j++) {
            ull a = i==0 ? (K/R + K%R) : K/R;
            ull b = j==0 ? ((K-1)/R + (K-1)%R) : (K-1)/R;
            inter_count += a * b  % CONST;
        }
    }
    inter_count /= 2;

    // inter_count = inter_count * c % CONST;
    ull z = inter_count;
    inter_count = 0;
    for(ull i=0; i<R; i++) {
        for(ull j=0; j<R; j++) {
            ull a = i==0 ? (z/R + z%R) : z/R;
            ull b = j==0 ? (c/R + c%R) : c/R;
            inter_count += a * b % CONST;
        }
    }
    
    total_count = (total_count + inter_count) % CONST;

    cout << total_count << endl;

    // */

    /*
    for(ull i=0; i<K; i++) {
        total_count = (total_count + (c*i%CONST)) % CONST;
    }

    cout << total_count << endl;
    // */

    return 0;
}