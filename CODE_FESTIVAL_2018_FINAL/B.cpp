#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

auto memo = map<pair<int,int>,int>();

int combi(int n, int r) {
    try {
        return memo.at(pair<int,int>(n,r)); 
    } catch(out_of_range&) {;}

    if(r==1)
        return n;
    auto ret = n * combi(n-1, r-1) / r;
    memo[pair<int,int>(n,r)] = ret;
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> r(M);
    for(int i=0; i<M; i++)
        cin >> r[i];

    double p = 1.0 / N;

    int c = N;
    double q = 1.0;
    for(int i=0; i<M; i++) {
        q *= combi(c, r[i]) * pow(p, r[i]);
        c -= r[i];
        cout << q << ' ' << c << endl;
    }

    cout << q << endl;

    return 0;
}