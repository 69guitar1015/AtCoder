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

bool pair_smaller(pair<int, pair<string,int>> a, pair<int, pair<string,int>> b) {
    if(a.second.first != b.second.first)
        return a.second.first < b.second.first;
    else
        return a.second.second > b.second.second;
    
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, pair<string,int>>> sp(N);
    for(int i=0; i<N; i++) {
        string s;
        int p;
        cin >> s >> p;
        sp[i] = pair<int, pair<string,int>>(i+1, pair<string,int>(s, p));
    }

    sort(sp.begin(), sp.end(), pair_smaller);

    for(auto& a : sp) {
        cout << a.first << endl;
    }

    return 0;
}