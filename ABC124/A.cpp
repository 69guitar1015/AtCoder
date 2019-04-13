#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    int A, B;

    cin >> A >> B;

    int X = max(A, B);

    if(A == X) {
        A = A - 1;
    } else {
        B = B - 1;
    }

    X = X + max(A, B);

    cout << X << endl;

    return 0;
}