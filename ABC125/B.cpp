#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N;
    vector<pair<int, int>> VC;

    cin >> N;

    for(int i=0; i<N; i++)
        VC.push_back(pair<int, int>(0, 0));

    for(int i=0; i<N; i++)
        cin >> VC[i].first;

    for(int i=0; i<N; i++)
        cin >> VC[i].second;

    sort(VC.begin(), VC.end(), [](const auto& a, const auto& b) {
        return a.first - a.second > b.first - b.second;
    });

    int ans = 0;
    for(int i=0; i<N; i++)
        if(VC[i].first - VC[i].second > 0)
            ans += VC[i].first - VC[i].second;

    cout << ans << endl;

    return 0;
}