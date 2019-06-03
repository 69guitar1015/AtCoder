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

bool ok(string s) {
    for(int i=0; i<(int)s.size()-1; i++) {
        if(s.substr(i, 2)=="##")
            return false;
    }
    return true;
}

int main() {
    int N, A, B, C, D;
    string S;

    cin >> N >> A >> B >> C >> D;
    cin >> S;

    bool clear_sunuke = ok(S.substr(A-1, C-A+1));
    bool clear_funuke = ok(S.substr(B-1, D-B+1));
    if(!clear_funuke || !clear_sunuke)
        cout << "No" << endl;
    else if(C < D) {
        cout << "Yes" << endl;
    } else {
        bool f = false;
        for(int i=B-1; i<=D-1; i++) {
            if(S.substr(i-1, 3)=="...") {
                f = true;
                break;
            }
        }
        if(f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}