#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    unsigned int N;
    float average = 0;

    cin >> N;

    for(int i=1; i<=N; i++) {
        average += 10000.0 * i / N;
    }

    cout << average << endl;

    return 0;
}