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
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> subtree(n + 1), dp(n + 1);
    function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        subtree[node] = v[node];
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            dfs(child, node);
            subtree[node] += subtree[child];
            dp[node] += (dp[child] + subtree[child]);
        }
    };
    dfs(1, 0);
    vector<int> ans(n + 1);
    ans[1] = dp[1];
    int total = subtree[1];

    function<void(int, int)> dfs2 = [&](int node, int par) -> void
    {
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            ans[child] = ans[node] + (total - 2 * subtree[child]);
            dfs2(child, node);
        }
    };

    dfs2(1, 0);
    cout << *max_element(ans.begin() + 1, ans.end());
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
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
