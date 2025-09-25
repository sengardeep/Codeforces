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
    int n;
    string s;
    cin >> n >> s;
    auto helper = [&](char c) -> int
    {
        vector<int> pos;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                pos.pb(i);
        }
        int k = pos.size();
        if (k <= 1)
            return 0;
        vector<int> q(k);
        for (int i = 0; i < k; i++)
            q[i] = pos[i] - i;
        int mid = q[k / 2];
        int ans = 0;
        for (int i = 0; i < k; ++i)
            ans += abs(q[i] - mid);
        return ans;
    };
    int ans = min(helper('a'), helper('b'));
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
