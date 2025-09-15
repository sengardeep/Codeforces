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
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<int> vis(n+1,false);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    vis[node]=true;
    for(auto child : adj[node]){
        if(child==par) continue;
        if(vis[child]==true)
        {
            vis[child]=false;
            return;
        }
        dfs(child,node);
    }
   };
   dfs(1,0);
   for(int i=1;i<=n;i++)
   {
       if(!vis[i]) 
       {
           cout<<"NO"<<endl;
           return;
       }
   }
   cout<<"YES"<<endl;
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
