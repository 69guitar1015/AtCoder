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
    int S;
    cin >> S;
    auto u = S / 100;
    auto d = S % 100;

    if((d==0 && u==0) || (u==0 && d >= 13) || (u>=13 && d==0) || (u >= 13 && d >= 13))
        cout << "NA" << endl;
    else if(1 <= u && u <= 12 && (d==0 || d >= 13))
        cout << "MMYY" << endl;
    else if((u==0 || u >= 13) && 1 <= d && d <= 12)
        cout << "YYMM" << endl;   
    else
        cout << "AMBIGUOUS" << endl;

    return 0;
}