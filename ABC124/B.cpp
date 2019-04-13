#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    int H[20] = {0};

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> H[i];
    }

    int count = 0;
    for(int i=0; i<N; i++) {
        bool flag = true;
        for(int j=0; j<i; j++) {
            if(H[j] > H[i]) {
                flag = false;
                break;
            }
        }

        if(flag)
            count = count + 1;
    }

    cout << count << endl;

    return 0;
}