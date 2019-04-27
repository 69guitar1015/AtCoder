#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
ull gcd(ull m, ull n) {
    while(true) {
        if(n==0)
            return m;
 
        ull tmp = n;
        n = m % n;
        m = tmp;
    }
}
 
pair<ull, int> exec(ull x, vector<ull>& A) {
    ull min_gcd = x;
    ull second_min_gcd = x;
    int min_idx, second_min_idx;
    for(int i=0; i<(int)A.size(); i++) {
        if(second_min_gcd==1)
            return pair<ull, int>(1, 0);
 
        ull t = gcd(x, A[i]);
        if(min_gcd > t) {
            min_gcd = t;
            min_idx = i;
        } else if (second_min_gcd > t) {
            second_min_gcd = t;
            second_min_idx;
        }
    }
 
    return pair<ull, int>(second_min_gcd, min_idx);
}
 
int main() {
    int N;
    cin >> N;
 
    vector<ull> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
 
    if(N == 2)
        cout << max(A[0], A[1]) << endl;
    else {
        auto zero = exec(A[0], A);
        auto one = exec(A[1], A);
 
        int start, idx;
        if(zero.first > one.first) {
            start = 0;
            idx = zero.second;
        } else {
            start = 1;
            idx = one.second;
        }
 
        auto x = A[start];
        for(int i=0; i<N; i++) {
            if(i == idx)
                continue;
            x = gcd(x, A[i]);
        }
        cout << x << endl;
    }
 
    return 0;
}