#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define MAX_PRIME (1000000001)

typedef unsigned long long int uint64;

int main() {
    bool primes[MAX_PRIME];
    primes[0] = 0;
    primes[1] = 0;
    for(uint64 i=2; i<MAX_PRIME; i++)
        primes[i] = 1;

    for(uint64 i=2; i<sqrt(MAX_PRIME); i++) {
        if(primes[i])
            for(uint64 j=i*i; j<MAX_PRIME; j *= i)
                primes[j] = 0;
    }

    cout << primes[5] << endl;

    return 0;
}