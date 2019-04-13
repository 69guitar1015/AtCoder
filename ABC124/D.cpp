#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct group {
    long long int length = 0;
    char sign;
};

int main() {
    long long int N, K;
    string S;

    cin >> N >> K;
    cin >> S;

    vector<group> groups;
    char sign = S[0];
    long long int length = 0;

    if(sign == '0')
        groups.push_back({0, '1'});
    else
        groups.push_back({0, '0'});

    for(auto c : S) {
        if(sign == c) {
            length++;
        } else {
            groups.push_back({length, sign});
            sign = c;
            length = 1;
        }
    }
    groups.push_back({length, sign});

    if(sign == '0')
        groups.push_back({0, '1'});
    else
        groups.push_back({0, '0'});

    long long int max_length = 0;
    for(auto& g : groups) {
        if(g.sign == '0')
            continue;
        max_length = max(max_length, g.length);
    }

    for(long long int i=0; i<max((unsigned long long int)0, groups.size()-2*K); i++) {
        if(groups[i].sign == '0')
            continue;

        long long int total_length = 0;
        for(long long int j=i; j<min((long long int)groups.size(), 2*K+1+i); j++)
            total_length += groups[j].length;

        if(max_length == S.length())
            break;

        max_length = max(max_length, total_length);
    }

    cout << max_length << endl;

    return 0;
}