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

enum V {
    A     = 0,
    BC    = 1,
};

vector<vector<V>> parse(string s) {
    auto l = vector<vector<V>>();
    auto crr = vector<V>();

    for(int i=0; i<(int)s.size(); i++) {    
        if(s[i]=='A') {
            crr.push_back(A);
        } else if (i+1 < (int)s.size() && s[i]=='B' && s[i+1]=='C') {
            crr.push_back(BC);
            i++;
        } else if(crr.size() > 0) {
            l.push_back(crr);
            crr = vector<V>();
        }
    }

    if(crr.size() > 0)
        l.push_back(crr);

    return l;
}

int count(vector<V> &p) {
    int c = 0;

    auto s = p.begin();
    while(s!=p.end() && (*s)==BC) {
        s++;
    }
    if(s == p.end())
        return 0;
    
    auto e = p.end()-1;
    while(e!=p.begin() && (*e)==A) {
        e--;
    }
    if(e==p.begin())
        return 0;

    if(e==s)
        return 0;

    int i = 0;
    for(auto pos=e; pos != s-1; pos--) {
        if((*pos) == A)
            c += i;
        else
            i++;
    }
    return c;
}

int main() {
    string s;
    cin >> s;

    auto l = parse(s);

    int cnt = 0;
    for(auto& p : l)
        cnt += count(p);

    cout << cnt << endl;


    return 0;
}