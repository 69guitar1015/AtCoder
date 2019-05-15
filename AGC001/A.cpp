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

    vector<int> moths(2*N);
    for(int i=0; i<2*N; i++)
        cin >> moths[i];

    sort(moths.begin(), moths.end());

    int length = 0;
    for(auto i=moths.begin(); i!=moths.end(); i += 2)
        length += *(i);
    cout << length << endl;
    
    return 0;
}