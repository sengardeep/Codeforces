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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];

    bool flag = false;
    for (char c : s) if (c == 'B') { flag = true; break; }

    if (!flag)
    {
        for (auto x : queries) cout << x << endl;
        return;
    }

    vector<int> diff(n), nxt(n), b(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            int count = 0, j = i;
            for (int step = 0; step < n && s[j] != 'B'; ++step)
            {
                count++;
                j = (j + 1) % n;
            }
            diff[i] = count;
            b[i] = j;
            nxt[i] = (j + 1) % n;
        }
        else
        {
            diff[i] = 0;
            b[i] = i;
            nxt[i] = (i + 1) % n;
        }
    }

    for (auto x : queries)
    {
        long long ans = 0, pos = 0;
        while (x > 0)
        {
            int g = diff[pos];
            if (x <= g)
            {
                ans += x;
                x = 0;
                break;
            }
            ans += (g + 1);
            x -= g;
            x /= 2;
            pos = nxt[pos];
        }
        cout << ans << endl;
    }
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
