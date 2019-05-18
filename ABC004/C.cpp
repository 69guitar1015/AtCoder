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
    ull N;
    cin >> N;

    // N==0  => 123456
    // N==5  => 234561
    // N==10 => 345612
    // ...
    int cards[6];    
    ull start_idx = (6 - (N / 5)%6)%6;
    for(int i=0; i<6; i++)
        cards[(i+start_idx)%6] = i+1;

    N = N % 5;

    for(ull i=0; i<N; i++)
        swap(cards[i%5], cards[i%5+1]);

    for(auto c : cards)
        cout << c;
    cout << endl;

    return 0;
}