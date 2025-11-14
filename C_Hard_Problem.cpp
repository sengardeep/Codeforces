#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<string> s(n), revs(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        revs[i] = s[i];
        reverse(revs[i].begin(), revs[i].end());
    }

    const long long INF = 4e18;

    // dp[i][0] = min cost if s[i] is not reversed
    // dp[i][1] = min cost if s[i] is reversed
    vector<vector<long long>> dp(n, vector<long long>(2, INF));

    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 1; i < n; i++) {

        // prev not reversed -> current not reversed
        if (s[i-1] <= s[i])
            dp[i][0] = min(dp[i][0], dp[i-1][0]);

        // prev not reversed -> current reversed
        if (s[i-1] <= revs[i])
            dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);

        // prev reversed -> current not reversed
        if (revs[i-1] <= s[i])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);

        // prev reversed -> current reversed
        if (revs[i-1] <= revs[i])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
    }

    long long ans = min(dp[n-1][0], dp[n-1][1]);
    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}