#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int c0=0, c1=0;
    for(int i=0; i<S.size(); i++) {
        if(S[i] != '0' + i % 2)
            c0++;
        if(S[i] != '0' + (i+1) % 2)
            c1++;
    }

    cout << min(c0, c1) << endl;

    return 0;
}