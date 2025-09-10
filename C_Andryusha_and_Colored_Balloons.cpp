#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n + 1);
    function<void(int, int)> dfs = [&](int node, int p) -> void
    {
        par[node] = p;
        for (auto child : adj[node])
        {
            if (child == p)
                continue;
            dfs(child, node);
        }
    };
    dfs(1, 0);
    vector<int> ans(n + 1);
    ans[1] = 1;
    int c = 2, mx = 1;
    queue<int> q;
    for (auto child : adj[1])
    {
        q.push(child);
        ans[child] = c;
        mx = max(mx, c);
        c++;
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int c = 1;
        for (auto child : adj[node])
        {
            if (child != par[node])
            {
                while (c == ans[node] || c == ans[par[node]])
                    c++;
                q.push(child);
                ans[child] = c;
                mx = max(mx, c);
                c++;
            }
        }
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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
