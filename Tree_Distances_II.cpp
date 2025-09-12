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
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<int> indp(n+1,0),outdp(n+1,0);
   vector<int> subtree(n+1,1);
   function<void(int,int)> indfs = [&](int node,int par)->void{
    for(auto child : adj[node]){
        if(child==par) continue;
        indfs(child,node);
        subtree[node]+=subtree[child];
        indp[node]+=subtree[child]+indp[child];
    }
   };
   indfs(1,0);
//    for(auto it : subtree) cerr<<it<<" ";
   outdp[1]=indp[1];
   function<void(int,int)> outdfs = [&](int node,int par)->void{
    for(auto child : adj[node]){
        if(child==par) continue;
        outdp[child] = n + outdp[node] - 2ll*subtree[child];
        outdfs(child,node);
    }
   };
   outdfs(1,0);
   for(int i=1;i<=n;i++) cout<<outdp[i]<<" ";
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