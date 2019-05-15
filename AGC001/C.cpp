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

vector<int> bfs(vector<vector<int>>& edges, int N, int p) {
    vector<int> dist(N);
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++)
        dist[i] = -1;
    
    dist[p] = 0;
    q.push(pair<int,int>(p,0));

    while(!q.empty()) {
        auto x = q.front();
        auto p = x.first;
        auto d = x.second;
        q.pop();

        for(auto e : edges[p]) {
            if(dist[e] == -1) {
                dist[e] = d+1;
                q.push(pair<int,int>(e,d+1));
            }
        }
    }

    return dist;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> edges(N);
    for(int i=0; i<N; i++)
        edges.push_back(vector<int>());

    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    auto dis0 = bfs(edges, N, 0);
    auto a = distance(dis0.begin(), max_element(dis0.begin(), dis0.end()));
    auto disa = bfs(edges, N, a);
    auto dia = *max_element(disa.begin(), disa.end());
    auto rad = dia / 2; 

    for(auto d : disa) {
        cout << ' ' << d;
    }
    cout << endl;

    vector<int> center;
    for(int i=0; i<N; i++)
        if(disa[i]==rad)
            center.push_back(i);

    for(auto c : center) {
        auto disc = bfs(edges, N, c);

        cout << dia << ' ' << rad << ' ' << c << endl;
        
        for(auto d : disc) {
            cout << ' ' << d;
        }
        cout << endl;        
    }

    return 0;
}