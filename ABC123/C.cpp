#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long int N;
    vector<long long int> cap(5);
    
    cin >> N;
    for(auto& c : cap)
        cin >> c;
    
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long int minimum = *min_element(cap.begin(), cap.end());

    cout << 5 + (N-1) / minimum << endl;;

    return 0;
}