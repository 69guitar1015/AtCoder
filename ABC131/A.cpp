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
    string S;
    cin >> S;

    bool f = false;
    for(int i=0; i<3; i++)
        if(S[i]==S[i+1])
            f = true;

    if(f)
        cout << "Bad" << endl;
    else
        cout << "Good" << endl;

    return 0;
}