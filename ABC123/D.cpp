#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long int X, Y, Z, K, x;
    vector<long long int> A, B, C;

    cin >> X >> Y >> Z >> K;
    for(int i=0; i<X; i++) {
        cin >> x;
        A.push_back(x);
    }
    for(int i=0; i<Y; i++) {
        cin >> x;
        B.push_back(x);
    }
    for(int i=0; i<Z; i++) {
        cin >> x;
        C.push_back(x);
    }

    sort(A.begin(), A.end(), greater<long long int>());
    sort(B.begin(), B.end(), greater<long long int>());
    sort(C.begin(), C.end(), greater<long long int>());

    long long int k = 0;
    auto pos_a = A.begin(), pos_b = B.begin(), pos_c = C.begin();
    for(int i=0; i<K; i++) {
        bool is_last_a = (pos_a == A.end()-1);
        bool is_last_b = (pos_b == B.end()-1);
        bool is_last_c = (pos_c == C.end()-1);

        if(is_last_a && is_last_b && is_last_c)
            break;

        auto diff_a = *(A.begin()) - *pos_a;
        auto diff_b = *(B.begin()) - *pos_b;
        auto diff_c = *(C.begin()) - *pos_c;

        if(!is_last_a
           && diff_a <= diff_b && diff_a <= diff_c)
           pos_a++;
        else if(
           !is_last_b
           && diff_b <= diff_a && diff_b <= diff_c)
           pos_b++;
        else
            pos_c++;
    }

    vector<long long int> cand;
    for(auto a=A.begin(); a!=pos_a+1; a++)
        for(auto b=B.begin(); b!=pos_b+1; b++)
            for(auto c=C.begin(); c!=pos_c+1; c++) {
                // cout << *a << " " << *b << " " << *c << endl;
                cand.push_back(*a+*b+*c);
            }
    sort(cand.begin(), cand.end(), greater<long long int>());
    
    for(int i=0; i<K; i++)
        cout << cand[i] << endl;

    return 0;
}