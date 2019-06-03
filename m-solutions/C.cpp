#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> comb(int n, int r) {
  vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

vector<vector<ll>> comb_table;

double p_exec(int k, int n, double p) {
    return pow(p, k) * pow(p, n-k) * comb_table[n-1][k-1];
}

double p_end(int l, int N, double q) {
    return (pow(q, N)*pow(1-q, l-N)+pow(q, l-N)*pow(1-q, N)) * comb_table[l-1][N-1];
}

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    comb_table = comb(100, 100);

    double p = A / 100.0;
    double q = 1.0 * B / (B+C);

    double e = 0;
    for(int n=N; n < 2*N; n++) {
        double total_prob = 0;

        for(int l=N; l <=n; l++) {
            total_prob += p_exec(l, n, p) * p_end(l, N, q);
        }

        e += n * total_prob;
    }

    cout << e << endl;

    return 0;
}