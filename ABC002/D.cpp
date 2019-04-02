#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

void _combination(vector<int> v, vector<int> w, int start, int n, vector<vector<int>>* combi) {
    if(w.size()==n) {

        combi->push_back(w);
        return;
    }

    for(int i=start; i<v.size()-(n-w.size())+1; i++) {
        vector<int> y(w.size());
        copy(w.begin(), w.end(), y.begin());
        y.push_back(v[i]);
        _combination(v, y, i+1, n, combi);
    }
}

vector<vector<int>> combination(vector<int> v, unsigned n) {
    vector<vector<int>> combi(0);
    vector<int> w(0);
    _combination(v, w, 0, n, &combi);
    return combi;
}

int main() {
    unsigned int N, M;
    bitset<12> A[12];

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        A[i].reset();
        A[i].set(i);
    }

    for(int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        A[x-1].set(y-1);
        A[y-1].set(x-1);
    }
    
    int n_links[12];
    vector<vector<int>> target_links;
    for(int i=0; i<N; i++) {
        auto sum = A[i].count();
        n_links[i] = sum;
    }

    for(int i=0; i<N+1; i++) {
        target_links.push_back(vector<int>());
        for(int j=0; j<N; j++)
            if(n_links[j] >= i)
                target_links[i].push_back(j);
    }

    for(int i=N; i>=0; i--) {
        if(target_links[i].size() < i)
            continue;

        auto combi = combination(target_links[i], i);
        
        for(auto& c : combi) {
            bitset<12> mask;
            mask.reset();
            for(int j=0; j<N; j++)
                mask.set(j);

            for(auto v : c)
                mask &= A[v];
            
            if(mask.count() >= i) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 1 << endl;
    return 0;
}