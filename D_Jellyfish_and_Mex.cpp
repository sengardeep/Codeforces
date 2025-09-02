#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < n)
            {
                cnt[a[i]]++;
            }
        }

        n = 0;
        while (cnt[n] > 0)
            n++;

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = (cnt[0] - 1) * i;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                int curr = (cnt[i] - 1) * j + i + dp[i - 1][i];
                dp[i][j] = min(dp[i][j], curr);
            }
        }

        cout << dp[n - 1][n] << endl;
    }

    return 0;
}
