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
    cin >> N;

    
    for(int i=0; i<N; i++) {
        vector<int> v = vector<int>(N);
        for(int j=0; j<N; j++)
            v.push_back(0);
        A.push_back(v);
    }

    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        A[a-1][b-1] = 1;
        A[b-1][a-1] = 1;
    }


    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << '\t' << A[i][j];
        }
        cout << endl;
    }
    return 0;
}