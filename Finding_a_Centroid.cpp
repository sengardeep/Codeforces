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
   vector<int> subtree(n+1);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    subtree[node]=1;
    for(auto child : adj[node]){
        if(child==par) continue;
        dfs(child,node);
        subtree[node]+=subtree[child];
    }
   };
   dfs(1,0);
   //For each node find max(n-subtree[node],max(subtree[child]));
   vector<int> ans(n+1);
   function<void(int,int)> dfs2=[&](int node,int par)->void{
    ans[node]=n-subtree[node];
    for(auto child : adj[node]){
        if(child==par) continue;
        dfs2(child,node);
        ans[node]=max(ans[node],subtree[child]);
    }
   };
   dfs2(1,0);
   int centeroid=-1,minVal=1e10;
   for(int i=1;i<=n;i++){
    if(ans[i]<minVal){
        centeroid=i;
        minVal=ans[i];
    }
   }
   cout<<centeroid;
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
