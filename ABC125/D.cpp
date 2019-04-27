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

    vector<ll> A(N);
    vector<ull>absA(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
        absA[i] = abs(A[i]);
    }

    int s = 1;
    for(auto i=A.begin(); i!=A.end(); i++)
        s *= (*i >= 0) ? 1 : -1;

    ull sum = 0;
    for(auto i=absA.begin(); i!=absA.end(); i++)
        sum += *i;

    ull mini = 0;
    if(s == -1)
        mini = *min_element(absA.begin(), absA.end());

    cout << sum - 2*mini << endl;

    return 0;
}