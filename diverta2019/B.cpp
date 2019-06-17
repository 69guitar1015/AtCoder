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

    vector<pair<ull,ull>> xy(N);
    for(int i=0; i<N; i++)
        cin >> xy[i].first >> xy[i].second;

    vector<vector<pair<ull,ull>>> pq(N);
    for(int i=0; i<N; i++) {
        pq[i] = vector<pair<ull,ull>>(N);
        pq[i][i].first = pq[i][i].second = 0;
        for(int j=0; j<N; j++) {
            pq[i][j].first = xy[j].first - xy[i].first;
            pq[i][j].second = xy[j].second - xy[i].second;
        }
    }

    map<pair<ull,ull>,int> pq_count;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(pq[i][j]==pair<ull,ull>(0,0))
                continue;
            pq_count[pq[i][j]]++;
        }
    }

    int max_count = 0;
    for (auto i : pq_count)
        if(max_count < i.second)
            max_count = i.second;

    cout << N - max_count << endl;

    return 0;
}
