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
   vector<vector<int>> dp(n + 1, vector<int>(2, 0));
   function<void(int,int)> dfs = [&](int node,int par)->void{
      for(auto child : adj[node]) {
         if(child==par) continue;
         dfs(child,node);
         dp[node][0] += max(dp[child][0],dp[child][1]);
      }
      for(auto child : adj[node]){
         if(child == par) continue;
         dp[node][1] = max(dp[node][1],1+dp[node][0]+dp[child][0]-max(dp[child][0],dp[child][1]));
      }
   };
   dfs(1,0);
   cout<<max(dp[1][0],dp[1][1]);
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
