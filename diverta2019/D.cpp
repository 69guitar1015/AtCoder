#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int earn(int N, vector<ull>& gsbX, vector<ull>& gsbY) {
    vector<double> rate(3);
    for(int i=0; i<3; i++)
        rate[i] = 1.0 * gsbY[i] / gsbX[i];

    vector<size_t> indices(rate.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&rate](size_t i1, size_t i2) {
        return rate[i1] > rate[i2];
    });

    vector<ull> stock(3);
    for(auto i : indices) {
        if(rate[i] < 1.0)
            break;
        
        stock[i] = N / gsbX[i];
        N = N % gsbX[i];
    }

    for(auto i : indices) {
        N += gsbY[i] * stock[i];
    }

    return N;
}

int main() {
    ull N;
    vector<ull> gsbA(3), gsbB(3);
    cin >> N;
    cin >> gsbA[0] >> gsbA[1] >> gsbA[2]; 
    cin >> gsbB[0] >> gsbB[1] >> gsbB[2]; 


    N = earn(N, gsbA, gsbB);
    N = earn(N, gsbB, gsbA);

    cout << N << endl;

    return 0;
}