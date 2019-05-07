#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main() {
    ull H, W, N, sr, sc;
    string S, T;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    cin >> S;
    cin >> T;


    map<char, int> index;
    index['L'] = 0;
    index['R'] = 1;
    index['U'] = 2;
    index['D'] = 3;

    ull cumS[4] = {0}, cumT[4] = {0};
    for(ull i=0; i<N; i++) {
        cumS[index[S[i]]]++;

        bool f = false;
        f = f || (sc - (cumS[index['L']] - cumT[index['R']]) <= 0);
        f = f || (sc + (cumS[index['R']] - cumT[index['L']]) >= W+1);
        f = f || (sr - (cumS[index['U']] - cumT[index['D']]) <= 0);
        f = f || (sr + (cumS[index['D']] - cumT[index['U']]) >= H+1);

        if(f) {
            cout << "NO" << endl;
            return 0;
        }

        f = true;
        if(T[i]=='L')
            f = f && (sc-(cumT[index['L']]-cumS[index['R']]) >= 2);
        else if(T[i]=='R')
            f = f && (sc+(cumT[index['R']]-cumS[index['L']]) <= W-1);
        else if(T[i]=='U')
            f = f && (sr-(cumT[index['U']]-cumS[index['D']]) >= 2);
        else
            f = f && (sr+(cumT[index['D']]-cumS[index['U']]) <= H-1);

        if(f)
            cumT[index[T[i]]]++;

    }

    cout << "YES" << endl;

    return 0;
}