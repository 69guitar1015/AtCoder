#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
bool check_finished(vector<vector<int>> &map, int H, int W) {
    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
            if(map[i][j]==0)
                return false;
    return true;
}

pair<int,int> directions[4] = {
    pair<int,int>(-1, 0),
    pair<int,int>(0, -1),
    pair<int,int>(1, 0),
    pair<int,int>(0, 1),
};

int main() {
    int H, W;
    cin >> H >> W;
 
    vector<vector<int>> map(H+2);
    for(int i=0; i<W+2; i++) {
        map[0].push_back(-1);
        map[H+1].push_back(-1);
    }
 
    for(int i=1; i<=H; i++) {
        map[i].push_back(-1);
 
        string s;
        cin >> s;
        auto cs = s.c_str();
        for(int j=0; j<W; j++) {
            int v = cs[j]=='.' ? 0 : 1;
            map[i].push_back(v);
        }
 
        map[i].push_back(-1);
    }
 
    ll sum = 0;
    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
            sum += map[i][j];
    if(sum == 0 || sum == H * W) {
        cout << 0 << endl;
        return 0;
    }
    
    int count = 0;
    while(true) {
        count++;
 
        vector<pair<int,int>> update_cand;
        for(int i=1; i<=H; i++) {
            for(int j=1; j<=W; j++) {
                if(map[i][j] != count)
                    continue;
            
                update_cand.push_back(pair<int,int>(i,j));
            }
        }
 
        for(auto& c : update_cand)
            for(auto& d : directions)
                if(map[c.first+d.first][c.second+d.second]==0)
                    map[c.first+d.first][c.second+d.second] = count+1;

        if(check_finished(map, H, W))
            break;
    }
 
    cout << count << endl;
 
    return 0;
}