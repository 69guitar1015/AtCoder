#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string w;
    cin >> w;

    stringstream ss;
    for(auto& c : w) {
        if(c!='a' && c!='i' && c!='u' && c!='e' && c!='o') {
            ss << c;
        }
    }

    cout << ss.str() << endl;

    return 0;
}