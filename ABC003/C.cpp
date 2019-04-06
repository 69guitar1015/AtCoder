#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    unsigned int N, K;
    vector<unsigned int> R;
    double score = 0;

    cin >> N >> K;

    for(int i=0; i<N; i++) {
        unsigned int r;
        cin >> r;
        R.push_back(r);
    }

    sort(R.begin(), R.end());
    for(auto r=R.begin()+(N-K); r!=R.end(); r++)
        score = (score + *r) / 2.0;
    printf("%.10f\n", score);
    return 0;
}