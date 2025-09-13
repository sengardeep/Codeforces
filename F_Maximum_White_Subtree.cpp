#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   vector<int> v(n+1);
   for(int i=1;i<=n;i++) cin>>v[i];
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<int> dp(n+1);
   function<void(int,int)> dfs = [&](int node,int par)->void{
    if(v[node]==1) dp[node]=1;
    else dp[node]=-1;
    for(auto child : adj[node]){
        if(child==par) continue;
        dfs(child,node);
        if(dp[child]>0) dp[node]+=dp[child];
    }
   };
   dfs(1,0);
//    for(auto it : dp) cerr<<it<<" ";
   vector<int> ans(n+1);
   function<void(int,int)> dfs2=[&](int node,int par)->void{
    //ReRooting
    ans[node]=dp[node];
    for(auto child : adj[node]){
        if(child==par) continue;
        dp[node] -= max(0LL,dp[child]);
        dp[child] += max(0LL,dp[node]);
        dfs2(child,node);
        dp[child] -= max(0LL,dp[node]);
        dp[node] += max(0LL,dp[child]);
    }
   };
   dfs2(1,0);
   for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
