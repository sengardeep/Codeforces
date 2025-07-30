#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

// Precompute combinations nCr using Pascal's triangle
vector<vector<int>> comb;

void precomputeComb(int N) {
    comb.assign(N+1, vector<int>(N+1, 0));
    for (int i = 0; i <= N; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // dp1[a][k]: number of non-decreasing arrays of length k ending with <= a
    vector<vector<int>> dp1(n+2, vector<int>(m+2, 0));
    for (int a = 1; a <= n; ++a) dp1[a][1] = 1;
    for (int k = 2; k <= m; ++k) {
        for (int a = 1; a <= n; ++a) {
            for (int prev = 1; prev <= a; ++prev) {
                dp1[a][k] = (dp1[a][k] + dp1[prev][k-1]) % MOD;
            }
        }
    }

    // dp2[b][k]: number of non-increasing arrays of length k starting with >= b
    vector<vector<int>> dp2(n+2, vector<int>(m+2, 0));
    for (int b = 1; b <= n; ++b) dp2[b][1] = 1;
    for (int k = 2; k <= m; ++k) {
        for (int b = 1; b <= n; ++b) {
            for (int next = b; next <= n; ++next) {
                dp2[b][k] = (dp2[b][k] + dp2[next][k-1]) % MOD;
            }
        }
    }

    // Calculate the answer
    int ans = 0;
    // For each split point: a <= b
    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            ans = (ans + 1LL * dp1[a][m] * dp2[b][m] % MOD) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}