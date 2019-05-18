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
    char C[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            cin >> C[i][j];
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << C[3-i][3-j];
            if(j < 3)
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}