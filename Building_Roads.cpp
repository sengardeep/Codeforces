#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int> adj[n+1];
   for(int i=0;i<m;i++) {
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<bool> vis(n+1,false);
   function<void(int)> dfs=[&](int node)->void{
    vis[node]=true;
    for(auto child : adj[node]){
        if(vis[child]) continue;
        dfs(child);
    }
   };
   vector<pii> ans;
   int prev=-1,curr=-1;
   for(int i=1;i<=n;i++) {
    if(!vis[i]){
        if(prev==-1) prev=i;
        else if(curr==-1) 
        {
            curr=i;
            ans.pb({prev,curr});
            prev=curr;
            curr=-1;
        }
        dfs(i);
    }
   }
   cout<<ans.size()<<endl;
   for(auto [u,v] : ans) cout<<u<<" "<<v<<endl;
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
