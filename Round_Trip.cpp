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
   map<pii,int> map;
   for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    if(map.count({u,v}) || map.count({v,u})) continue;
    map[{u,v}]++;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<bool> vis(n+1,false);
   int flag=0,x=-1;
   vector<int> parent(n+1);
   function<void(int,int)> dfs = [&](int node,int par)->void{
    parent[node]=par;
    vis[node]=true;
    for(auto child : adj[node]){
        if(child == par) continue;
        if(vis[child]){
            flag=1;
            parent[child]=node;
            x=child;
            return;
        }
        dfs(child,node);
    }
   };
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i,0);
        if(flag==1) break;
    }
   }
   if(flag)
   {
    vector<int> ans;
    int y=x;
    for(auto it : parent) cerr<<it<<" ";
    while(parent[x] != y){
        ans.pb(x);
        x=parent[x];
    }
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it<<" ";
   }
   else cout<<"IMPOSSIBLE";
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
