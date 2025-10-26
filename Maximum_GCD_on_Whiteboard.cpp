#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> map(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        map[x]++;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + map[i];

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int idx = min(n, 4 * i - 1),mul = 0;
        if (4 * i - 1 <= n)
        for (int j = i; j <= 3 * i; j += i) mul += map[j];
        else
        for (int j = i; j <= n; j += i) mul += map[j];
        if (k >= pre[idx] - mul) ans = i;
    }
    cout << ans << endl;
}

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
        solve();
    }

    return 0;
}
