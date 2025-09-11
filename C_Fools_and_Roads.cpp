#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,q;
   cin>>n;
   vector<int> adj[n+1];
   vector<pii> edges;
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    edges.pb(make_pair(u,v));
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<vector<int>> dp(n+1,vector<int>(19,0)); //Don't forget to change 19 according to log2(n)
   vector<int> level(n+1,0);
   //Binary Lifting
   function<void(int,int)> dfs = [&](int node,int par)->void{
       dp[node][0]=par;
       for(int i=1;i<=18;i++){
           dp[node][i]=dp[dp[node][i-1]][i-1];
       }
       for(auto child : adj[node]){
           if(child==par) continue;
           level[child]=level[node]+1;
           dfs(child,node);
       }
   };
   dfs(1,0);
   //Function to find kth parent of a node
   auto findKthPar = [&](int node,int k){
       int cnt=0;
       while(k){
           if(k&1){
               node=dp[node][cnt];
           }
           cnt++;
           k>>=1;
       }
       return node;
   };
   //Function to find LCA of two nodes
   function<int(int,int)> lca = [&](int a,int b)->int{
       if(level[a]>level[b]) swap(a,b);
       int d = level[b]-level[a];
       b=findKthPar(b,d);
       if(b==a) return a;
       for(int i=18;i>=0;i--){
           if(dp[a][i] != dp[b][i]){
               a=dp[a][i];
               b=dp[b][i];
           }
       }
       return dp[a][0];
   };
   cin>>q;
   vector<int> pre(n+1,0);
   //We'll Apply Prefix Sum technique on trees (+1 on both nodes and -1 on LCA && parent of LCA)
   while(q--){
    int u,v;
    cin>>u>>v;
    pre[v]+=1;
    pre[u]+=1;
    int L = lca(u,v);
    // dbg(L);
    pre[L]-=1;
    pre[dp[L][0]]-=1;
   }
   function<void(int,int)> dfs2=[&](int node,int par)->void{
    for(auto child : adj[node]){
        if(child == par) continue;
        dfs2(child,node);
        pre[node]+=pre[child];
    }
   };
   dfs2(1,0);
   vector<int> ans(n-1);
   for(int i=0;i<n-1;i++) ans[i]=min(pre[edges[i].first],pre[edges[i].second]);
   for(int i=0;i<n-1;i++) cout<<ans[i]<<" ";
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
