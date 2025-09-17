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
    // Ans : Number of cycles i.e. (E-V+C) (C-number of components)
    vector<int> vis(n + 1, 0);
    int comps = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comps++;
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            while (!st.empty())
            {
                int u = st.top();
                st.pop();
                for (auto v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }
        }
    }
    cout << (m - n + comps) << endl;
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
