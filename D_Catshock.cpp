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
   vector<vector<int>> adj(n+1);
   for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<int> contain(n+1,0);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    if(node==n) contain[node]=1;
    for(auto child : adj[node]){
        if(child==par) continue;
        dfs(child,node);
        if(contain[child]) contain[node]=1;
    }
   };
   dfs(1,0);
   vector<vector<int>> ans;
   function<void(int,int)> dfs2=[&](int node,int par)->void{
    for(auto child : adj[node]){
        if(child==par) continue;
        if(contain[child]==0){
            ans.pb({2,child});
        }
    }
    for(auto child : adj[node]){
        if(child==par) continue;
        if(contain[child]){
            ans.pb({1});
            dfs2(child,node);
        }
    }
   };
   dfs2(1,0);
   cout<<ans.size()<<endl;
   for(auto it : ans){
    for(auto x : it) cout<<x<<" ";
    cout<<endl;
   }
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
