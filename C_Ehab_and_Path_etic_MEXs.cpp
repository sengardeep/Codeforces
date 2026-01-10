#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    vector<pii> edges(n - 1);
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges[i] = {u, v};
        deg[u]++;
        deg[v]++;
    }
    int x = -1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] >= 3)
        {
            x = i;
            break;
        }
    }
    int label = 0;
    map<pii, int> map;
    if (x != -1)
    {
        for (auto it : adj[x])
        {
            map[{x, it}] = label;
            map[{it, x}] = label;
            label++;
        }
    }
    for (auto [u, v] : edges)
    {
        if (map.count({u, v}))
            cout << map[{u, v}] << endl;
        else
            cout << label++ << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}