#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool match(vector<ll>& a, vector<ll>& b) {
    if(a.size() != b.size())
        return false;
    
    for(auto i=a.begin(), j=b.begin(); i!=a.end(); i++, j++) {
        if(*i != *j)
            return false;
    }
    return true;
}

int main() {
    ll N, K;
    cin >> N >> K;

    auto A = vector<ll>(N);
    for(auto &a : A)
        cin >> a;

    auto s = vector<ll>();
    auto pos = vector<ll>(200000);
    for(auto &p : pos)
        p = -1;

    auto memo = vector<pair<ll, vector<ll> > >();

    for(ll k=0; k<K; k++) {
        for(ll i=0; i<N; i++) {
            auto a = A[i];
            if(pos[a] == -1) {
                s.push_back(a);
                pos[a] = k * N + i;
                continue;
            }

            while(s.back() != a) {
                pos[s.back()] = -1;
                s.pop_back();
            }
            pos[a] = -1;
            s.pop_back();
        }

        for(auto &m : memo) {
            if(match(m.second, s)) {
                auto span = k - m.first;
                k = K - (K-k) % span;
            }
        }

        auto x = vector<ll>(s);
        memo.push_back(make_pair(k, x));
    }

    for(auto &x : s)
        cout << x << ' ';
    cout << endl;

    return 0;
}