#include <bits/stdc++.h>
using namespace std;
#define int long long

static const long long INF = (long long)4e18;

long long pathDP(const vector<long long>& a, int l, int r) {
    // Cover linear segment a[l..r] with blocks of size 2 or 3 minimizing cost.
    // Cost of a pair [i,i+1] = |a[i]-a[i+1]|
    // Cost of a triple [i,i+1,i+2] = max - min over the three elements
    if (l > r) return 0;
    int len = r - l + 1;
    vector<long long> dp(len + 1, INF);
    dp[0] = 0;
    if (len >= 2) dp[2] = llabs(a[l] - a[l + 1]);
    if (len >= 3) {
        long long mx = max(a[l], max(a[l + 1], a[l + 2]));
        long long mn = min(a[l], min(a[l + 1], a[l + 2]));
        dp[3] = mx - mn;
    }
    for (int k = 4; k <= len; ++k) {
        long long pairCost = llabs(a[l + k - 2] - a[l + k - 1]);
        long long mx = max(a[l + k - 3], max(a[l + k - 2], a[l + k - 1]));
        long long mn = min(a[l + k - 3], min(a[l + k - 2], a[l + k - 1]));
        long long tripleCost = mx - mn;
        dp[k] = min(dp[k - 2] + pairCost, dp[k - 3] + tripleCost);
    }
    return dp[len];
}

void solve() {
    int n; 
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Try three ways to cover the circle, using DP on the remaining path:
    // 1) Pair (0,1), then cover [2..n-1]
    // 2) Pair (n-1,0), then cover [1..n-2]
    // 3) Triple (n-1,0,1), then cover [2..n-2]
    long long ans = INF;

    // Case 1: pair (0,1)
    if (n >= 2) {
        long long cost = llabs(a[0] - a[1]);
        long long rest = pathDP(a, 2, n - 1);
        if (rest < INF) ans = min(ans, cost + rest);
    }

    // Case 2: pair (n-1,0)
    if (n >= 2) {
        long long cost = llabs(a[n - 1] - a[0]);
        long long rest = pathDP(a, 1, n - 2);
        if (rest < INF) ans = min(ans, cost + rest);
    }

    // Case 3: triple (n-1,0,1)
    if (n >= 3) {
        long long mx = max(a[n - 1], max(a[0], a[1]));
        long long mn = min(a[n - 1], min(a[0], a[1]));
        long long cost = mx - mn;
        long long rest = pathDP(a, 2, n - 2);
        if (rest < INF) ans = min(ans, cost + rest);
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
