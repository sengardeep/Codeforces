#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> pref(m, INF);
    int ptr = 0;
    for (int i = 0; i < m; i++) {
        while (ptr < n && a[ptr] < b[i]) {
            ptr++;
        }
        if (ptr < n) {
            pref[i] = ptr;
            ptr++;
        } else {
            break; 
        }
    }

    if (pref[m - 1] != INF) {
        cout << 0 << endl;
        return;
    }

    vector<int> suff(m, -1);
    ptr = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (ptr >= 0 && a[ptr] < b[i]) {
            ptr--;
        }
        if (ptr >= 0) {
            suff[i] = ptr;
            ptr--;
        } else {
            break; 
        }
    }

    int ans = INF;

    for (int i = 0; i < m; i++) {
        int left_idx = (i == 0) ? -1 : pref[i - 1];
        int right_idx = (i == m - 1) ? n : suff[i + 1];
        if (left_idx != INF && right_idx != -1 && left_idx < right_idx) {
            ans = min(ans, b[i]);
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    cin >> t; // Uncomment if there are test cases
    while(t--) solve();
    return 0;
}