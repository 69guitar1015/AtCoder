#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long int int64;
typedef unsigned long long int uint64;

uint64 C = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(auto& ai : a)
        cin >> ai;
    

    for(auto& ai : a)
        cout << ai << " ";
    cout << endl;

    return 0;
}