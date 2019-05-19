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
    bool visited;
    vector<int> neighbors;

    vertex() {
        this->visited = false;
        this->neighbors = vector<int>();
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vertex> vtx(N);

    for(int i=0; i<M; i++) {
        int u, v, z;
        cin >> u >> v >> z;
        vtx[u-1].neighbors.push_back(v-1);
        vtx[v-1].neighbors.push_back(u-1);
    }


    int count = 0;
    for(int i=0; i<N; i++) {
        if(vtx[i].visited)
            continue;
        count++;
        
        auto que = queue<int>();
        que.push(i);

        while(!que.empty()) {
            auto idx = que.front();
            que.pop();

            vtx[idx].visited = true;
            for(auto next_idx : vtx[idx].neighbors) {
                if(vtx[next_idx].visited)
                    continue;
                que.push(next_idx);
            }   
        }
    }
    
    cout << count << endl;

    return 0;
}