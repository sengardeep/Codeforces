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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> color(n + 1, -1);
    queue<pii> q;

    for (int i = 1; i <= n; i++)
    {
        if(color[i]==-1)
        {
            q.push({i, 0});
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front().first, par = q.front().second;
                q.pop();
                for (auto child : adj[node])
                {
                    if (child == par)
                        continue;
                    if (color[child] == color[node])
                    {
                        cout << "IMPOSSIBLE";
                        return;
                    }
                    if (color[child] == -1)
                    {
                        color[child] = color[node] ^ 1;
                        q.push({child, node});
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << color[i] + 1 << " ";
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
