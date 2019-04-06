#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>


using namespace std;

unsigned int count_combination(unsigned long long int n,
                               unsigned long long int r,
                               unsigned int upper) {
    if(n < r)
        return 0;

    cout << n << " " << r << " " << n-r << endl;
    if(n-r < r)
        r = n-r;
    
    unsigned long long int c = 1;
    vector<pair<int, bool>> denoms;
    for(int i=r; i>=1; i--)
        denoms.push_back(pair<int, bool>(i, true));

    for(int i=0; i<r; i++) {
        c = c * (n-i);
        for(auto& d : denoms) {
            if(d.second && c % d.first == 0) {
                c /= d.first;
                d.second = false;
            }
        }
    }

    for(auto& d : denoms) {
        if(d.second)
            printf("(%d,%d) ", d.first, d.second);
    }
    cout << endl;

    cout << c << endl;
    return c % upper;
}

int main() {
    unsigned int R, C, X, Y, D, L;
    unsigned int upper = (int)pow(10, 9) + 7;

    cin >> R >> C;
    cin >> X >> Y;
    cin >> D >> L;

    unsigned int n_pos, n_combi, n_pattern, n_ignore;
    n_pos = (R-X+1) * (C-Y+1) % upper;
    n_pattern = count_combination(D+L, D, upper);

    n_combi = count_combination(X*Y, D+L, upper) * n_pattern % upper;
    // n_combi -= 2*(count_combination((X-1)*Y, D+L, upper) * n_pattern);
    // n_combi -= 2*(count_combination(X*(Y-1), D+L, upper) * n_pattern);
    // n_combi += 3*(count_combination((X-1)*(Y-1), D+L, upper) * n_pattern);

    cout << n_pos << " " << n_combi << endl;
    cout << n_pos * n_combi << endl;

    return 0;
}