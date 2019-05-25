#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct F {
    multiset<ll> a;
    priority_queue<ll, vector<ll>> less_a;
    priority_queue<ll, vector<ll>, greater<ll>> greater_a;
    ll b;

    F() {
        this->a = multiset<ll>();
        this->b = 0;
    }

    void update(ll a, ll b) {
        this->a.insert(a);
        this->b = (this->b + b);
    }

    void print_minimum() {
        if(this->a.empty()) {
            cout << "0 0";
            return;
        }

        auto x = this->a.begin();
        for(int i=0; i<(this->a.size()-1)/2; i++)
            x++;

        ll ans = 0;
        for(auto a : this->a)
            ans += abs(a - *(x));
        ans += this->b;
        cout << *(x) << ' ' << ans << endl;
    }
};

int main() {
    int Q;
    cin >> Q;
    F f = F();

    for(int q=0; q<Q; q++) {
        char query_number;
        cin >> query_number;
        if(query_number == '1') {
            ll a, b;
            cin >> a >> b;
            f.update(a, b);
        } else {
            f.print_minimum();
        }

    }    
    return 0;
}