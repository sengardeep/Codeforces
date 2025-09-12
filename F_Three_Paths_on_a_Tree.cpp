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
   for(int i=1;i<n;i++) {
    int u,v;
    cin>>u>>v;
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
       for(int i=18;i>=0;i--){
           if(dp[a][i] != dp[b][i]){
               a=dp[a][i];
               b=dp[b][i];
           }
       }
       return (a == b) ? a : dp[a][0];
   };
   auto dist = [&](int a,int b)->int{
    int l = lca(a,b);
    return level[a]+level[b]-2*level[l];
   };
   //find Diameter Endpoints
   int a=1;
   for(int i=2;i<=n;i++) if(dist(1,i)>dist(1,a)) a=i;
   int b=1;
   for(int i=2;i<=n;i++) if(dist(a,i)>dist(a,b)) b=i;
   int diam=dist(a,b);
   //Now we go for each node and find contribution(max) 
   int c=-1,val=0;
   for(int i=1;i<=n;i++){
    if(i==a||i==b) continue;
    int d = (dist(i,a)+dist(i,b)-diam)/2;
    if(d>=val) {
        val=d;
        c=i;
    }
   }
   cout<<diam+val<<endl;
   cout<<a<<" "<<b<<" "<<c;
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
