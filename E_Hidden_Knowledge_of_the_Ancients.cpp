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
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    auto helper = [&](int k, int maxLen) -> int
    {
        if (k < 0 || maxLen <= 0) return 0;
        map<int, int> map;
        int i = 0, distinct = 0, res = 0;
        for (int j = 0; j < n; j++)
        {
            map[v[j]]++;
            if (map[v[j]] == 1) distinct++;
            while (distinct > k || j - i + 1 > maxLen)
            {
                int val = v[i++];
                map[val]--;
                if (map[val] == 0)
                {
                    map.erase(val);
                    distinct--;
                }
            }
            res += j - i + 1;
        }
        return res;
    };
    int ans = (helper(k, r) - helper(k, l - 1)) - (helper(k - 1, r) - helper(k - 1, l - 1));
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
