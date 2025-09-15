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
    int n,y;
    cin >> n >> y;
    vector<int> v(n);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    vector<int> map(maxi + 1, 0);
    for (int x : v) map[x]++;
    vector<int> pre(maxi + 1, 0);
    for (int i = 1; i <= maxi; i++) pre[i] = pre[i - 1] + map[i];
    int ans = -1e10;
    for (int i = 2; i <= maxi + 1; i++)
    {
        int k = (maxi + i - 1) / i; 
        int sumB = 0;
        int match = 0;
        for (int j = 1; j <= k; j++)
        {
            int high = min(maxi, j * i);
            int low = (j - 1) * i;
            int freq = pre[high] - (low <= maxi ? pre[low] : pre[maxi]);
            if (freq == 0) continue;
            sumB += j * freq;
            int avail = 0;
            if(j <= maxi) avail = map[j];
            match += min(avail, freq);
        }
        int printed = n - match;
        int income = sumB - y * printed;
        if (income > ans) ans = income;
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
