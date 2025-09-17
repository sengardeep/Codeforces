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
    string s;
    cin >> s;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    bool hasSelfLoop = false;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            hasSelfLoop = true;
        deg[v]++;
        adj[u].pb(v);
    }
    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    // Kahn's Algo
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            dp[i][s[i - 1] - 'a'] = 1; 
        }
    }
    int visited = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited++;
        for (int child : adj[node])
        {
            for (int c = 0; c < 26; c++)
            {
                int add = (s[child - 1] - 'a' == c);
                dp[child][c] = max(dp[child][c], dp[node][c] + add);
            }
            deg[child]--;
            if (deg[child] == 0)
                q.push(child);
        }
    }
    if (visited < n)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
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
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
