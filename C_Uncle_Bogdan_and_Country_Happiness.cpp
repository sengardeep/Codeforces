#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt; cin >> tt;

    while(tt--)
    {
        int n, m, possible = 1; cin >> n >> m;

        vector<int>adj[n + 1], subtree(n + 1), happy(n + 1), happiness(n + 1);

        for(int i = 1; i <= n; i++) cin >> subtree[i];
        for(int i = 1; i <= n; i++) cin >> happiness[i];

        for(int i = 1; i < n; i++)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        function<void(int, int)>dfs = [&](int node, int parent)
        {
            int happiChildren = 0;

            for(auto &i : adj[node])
            {
                if(i != parent)
                {
                    dfs(i, node);
                    subtree[node] += subtree[i];
                    happiChildren += happy[i];
                }
            }

            if((subtree[node] + happiness[node]) % 2 != 0) possible = 0;

            happy[node] = (subtree[node] + happiness[node]) / 2;

            possible &= (happy[node] >= happiChildren && happy[node] <= subtree[node]);
        };

        dfs(1, 1);

        cout << (possible ? "YES\n" : "NO\n");
    }
}