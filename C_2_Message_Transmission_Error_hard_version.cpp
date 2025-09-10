#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DH {
    static const int M1 = 1000000007;
    static const int M2 = 1000000009;
    static const int B1 = 911382323;
    static const int B2 = 972663749;
    vector<int> p1, p2, h1, h2;
    DH() {}
    DH(const string& s) {
        int n = (int)s.size();
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (int)((__int128)p1[i] * B1 % M1);
            p2[i + 1] = (int)((__int128)p2[i] * B2 % M2);
            h1[i + 1] = ( ( (__int128)h1[i] * B1 ) + (unsigned char)s[i] ) % M1;
            h2[i + 1] = ( ( (__int128)h2[i] * B2 ) + (unsigned char)s[i] ) % M2;
        }
    }
    inline pair<int,int> get(int l, int r) const {
        if (l > r) return {0,0};
        int x1 = (h1[r + 1] - (int)((__int128)h1[l] * p1[r - l + 1] % M1)) % M1;
        if (x1 < 0) x1 += M1;
        int x2 = (h2[r + 1] - (int)((__int128)h2[l] * p2[r - l + 1] % M2)) % M2;
        if (x2 < 0) x2 += M2;
        return {x1, x2};
    }
};

void solve() {
    string t;
    if (!(cin >> t)) return;
    int n = (int)t.size();
    if (n <= 1) {
        cout << "NO\n";
        return;
    }

    DH dh(t);

    auto eq = [&](int l1, int r1, int l2, int r2) -> bool {
        if (r1 - l1 != r2 - l2) return false;
        return dh.get(l1, r1) == dh.get(l2, r2);
    };

    int start_m = (n + 2) / 2; // ceil((n+1)/2)
    for (int m = start_m; m <= n - 1; ++m) {
        int k = 2 * m - n;
        if (k <= 0 || k >= m) continue;

        // Check t[m..n-1] == t[k..m-1]  (length n-m == m-k)
        if (!eq(m, n - 1, k, m - 1)) continue;

        // Check border of s (s prefix length m) has length k: s[0..k-1] == s[m-k..m-1]
        if (!eq(0, k - 1, m - k, m - 1)) continue;

        cout << "YES\n";
        cout << t.substr(0, m) << "\n";
        return;
    }

    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}
