#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N;
    cin >> S;

    vector<int> cumW, cumB;
    int pW=0, pB=0;
    for(int i=0; i<S.length(); i++) {
        if(S[i] == '#')
            pB++;

        if(S[S.length() - 1 - i] == '.')
            pW++;

        cumB.push_back(pB);
        cumW.push_back(pW);      
    }

    int ans = 0;
    while(true) {
        bool f = true;
        auto iB=cumB.begin(), iW=cumW.end()-1;
        while(iB != cumB.end()) {
            f = (min(*iB, *iW) == 0);
            if(!f)
                break;
            iB++; iW--;
        }
        if(f)
            break;

        ans++;

        int countB=0, countW=0;
        for(auto i=cumB.begin(); i!=cumB.end(); i++) {
            if((*i) > 1)
                break;
            countB++;
        }
        for(auto i=cumW.begin(); i!=cumW.end(); i++) {
            if((*i) > 1)
                break;
            countW++;
        }

        if(countB > countW)
          for(int i=0; i<cumB.size(); i++) {
            if(cumB[i] > 0)
                cumB[i] -= 1;
          }
        else
          for(int i=0; i<cumW.size(); i++) {
            if(cumW[i] > 0)
                cumW[i] -= 1;
          }
    }

    cout << ans << endl;
    return 0;
}