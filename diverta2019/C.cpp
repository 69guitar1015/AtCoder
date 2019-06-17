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

int main() {
    int N;
    cin >> N;
    
    vector<ll> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    auto neg_begin = A.begin();
    auto neg_end = A.begin();
    while(*(neg_end) < 0 && neg_end != A.end())
        neg_end++;
    auto pos_begin = neg_end;
    auto pos_end = A.end();

    vector<ll>::iterator a, b;
    if(neg_begin==neg_end) {
        a = pos_begin;
        b = pos_end-1;
    } else if(pos_begin==pos_end) {
        a = neg_begin;
        b = neg_end-1;
    } else {
        a = neg_begin;
        b = pos_end-1; 
    }

    vector<pair<ll,ll>> log;
    ll x = *a;
    for(auto i=pos_begin; i!=pos_end; i++){
        if(i==a || i==b)
            continue;
        log.push_back(make_pair(x, *i));
        x = x - *i;
    }
    log.push_back(make_pair(*b, x));
    x = *b - x;

    for(auto i=neg_begin; i!=neg_end; i++) {
        if(i==a || i==b)
            continue;
        log.push_back(make_pair(x, *i));
        x = x - *i;
    }

    cout << x << endl;
    for(auto& l : log)
        cout << l.first << ' ' << l.second << endl;
}
