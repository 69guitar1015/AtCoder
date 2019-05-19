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

class vertex {
public:
    int color;
    vector<pair<int,int>> neighbors;

    vertex() {
        this->color = -1;
        this->neighbors = vector<pair<int,int>>();
    }
};

int main() {
    int N;
    cin >> N;


    vector<vertex> vtx(N);

    for(int i=0; i<N-1; i++) {
        ull u, v, w;
        cin >> u >> v >> w;
        vtx[u-1].neighbors.push_back(pair<int,int>(v-1, w%2+2));
        vtx[v-1].neighbors.push_back(pair<int,int>(u-1, w%2+2));
    }

    auto que = queue<pair<int,int>>({pair<int,int>(0, 0)});

    while(!que.empty()) {
        auto& idx_c = que.front();
        auto idx = idx_c.first;
        auto c = idx_c.second;
        que.pop();

        vtx[idx].color = c;
        for(auto next : vtx[idx].neighbors) {
            if(vtx[next.first].color==-1) {
                auto next_idx = next.first;
                auto next_color = (next.second%2==0) ? c : 1-c;
                que.push(pair<int,int>(next_idx, next_color));
            }
        }
    }
    
    for(auto& v : vtx)
        cout << v.color << endl;

    return 0;
}