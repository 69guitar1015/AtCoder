#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    vector<char> repl = {'a', 't', 'c', 'o', 'd', 'e', 'r', '@'};
    
    cin >> s;
    cin >> t;

    for(int i=0; i<s.length(); i++) {
        bool cant_repl_s, cant_repl_t, not_equal_s_t;
        cant_repl_s = (s[i] == '@') && (find(repl.begin(), repl.end(), t[i]) == repl.end());
        cant_repl_t = (t[i] == '@') && (find(repl.begin(), repl.end(), s[i]) == repl.end());
        not_equal_s_t = (s[i] != '@' && t[i] != '@' && s[i] != t[i]);
        if(cant_repl_s || cant_repl_t || not_equal_s_t) {
            cout << "You will lose" << endl;
            return 0;
        }
    }

    cout << "You can win" << endl;

    return 0;
}