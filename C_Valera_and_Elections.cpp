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
    vector<pii> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> ans;
    vector<int> v(n+1,0);
    function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        for (auto child : adj[node])
        {
            if (child.first == par)
                continue;
            dfs(child.first, node);
            if(v[child.first]==0 && child.second==2){
                v[child.first]=1;
                ans.push_back(child.first);
            }
            v[node]+=v[child.first];
        }
    };
    dfs(1, 0);
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
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
