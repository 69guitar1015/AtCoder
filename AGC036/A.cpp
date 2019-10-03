#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ull S;
    cin >> S;

    ull max_prime = (ull)sqrt(S);

    auto pn = map<ull,bool>();
    // auto pn = vector<ull>(max_prime);

    pn[0] = 1;
    pn[1] = 1;

    auto q = queue<ull>();
    ull stop = max_prime;

    for(ull i = 2; i <= stop; i++) {
        if(pn[i]==1)
            continue;

        while(S % i == 0) {
            q.push(i);
            S /= i;
            stop = (ull)sqrt(S);
        }

        for(ull j = i; j<=stop; j*=i)
            pn[j] = 1;
    }
    q.push(S);

    ull w=1, h=1;

    for(int i=0; !q.empty(); i++, q.pop()){
        if(i%2==0)
            w *= q.front();
        else
            h *= q.front();
    }

    // if(w >= pow(10, 9) || h >= pow(10, 9)) {
    //     cout << '0 0 0 0 0 0';
    //     return 0;
    // }

    printf("0 0 %llu 0 0 %llu\n", w, h); 

    return 0;
}