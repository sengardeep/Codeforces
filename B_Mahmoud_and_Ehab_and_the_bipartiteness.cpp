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
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<pii> q;
    q.push({1,0});
    int one=0,two=0,flag=0;
    while(!q.empty()){
        int s=q.size();
        if(flag) one+=s;
        else two+=s;
        flag^=1;
        while(s--){
            int node=q.front().first,par=q.front().second;
            q.pop();
            for(auto child : adj[node]){
                if(child==par) continue;
                q.push({child,node});
            }
        }
    }
    int ans=(one*two)-(n-1);
    cout<<ans;
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
