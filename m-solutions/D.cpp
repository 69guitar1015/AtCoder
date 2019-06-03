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

int main() {
    int N;
    cin >> N;

    auto edges = vector<vector<int>>(N);
    for(int i=0; i<N; i++)
        edges[i] = vector<int>();

    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    auto c = vector<int>(N);
    for(int i=0; i<N; i++)
        cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());

    auto degrees = vector<int>(N);
    auto assign = vector<int>(N);
    for(int i=0; i<N; i++) {
        degrees[i] = edges[i].size();
        assign[i] = -1;
    }

    int max_degree = 0;
    int max_degree_idx = 0;
    for(int i=0; i<N; i++) {
        if(degrees[i] <= max_degree)
            continue;
        max_degree = degrees[i];
        max_degree_idx = i;
    }

    auto q = queue<int>();
    q.push(max_degree_idx);

    int i = 0;
    while(!q.empty()) {
        int n = q.front();
        q.pop();

        assign[n] = c[i];
        i++;
        
        auto neighbor_d = vector<pair<int, int>>();
        for(auto e : edges[n]) {
            if(assign[e] != -1)
                continue;
            neighbor_d.push_back(pair<int, int>(degrees[e], e));
        }
        sort(neighbor_d.begin(), neighbor_d.end(), greater<pair<int, int>>());

        for(auto x : neighbor_d)
            q.push(x.second);
    }

    q = queue<int>();
    q.push(0);

    auto visited = vector<bool>(N);
    for(int i=0; i<N; i++)
        visited[i] = false;

    int count = 0;
    while(!q.empty()) {
        int n = q.front();
        q.pop();

        visited[n] = true;

        for(auto e : edges[n]) {
            if(visited[e])
                continue;

            count += min(assign[n], assign[e]);
            q.push(e);
        }
    }

    cout << count << endl;
    for(auto x : assign)
        cout << x << ' ';
    cout << endl;

    return 0;
}