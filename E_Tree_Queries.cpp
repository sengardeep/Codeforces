#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>

void solve() {
   int n,q;
   cin>>n>>q;
   vector<vector<int>> adj(n+1);
   for(int i=1;i<n;i++) {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   vector<vector<int>> dp(n+1,vector<int>(19,0));
   vector<int> level(n+1,0);
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
    return dp[a][0];
   };
   while(q--){
    int k;
    cin>>k;
    int maxLevel=-1,lowerNode=0;
    vector<int> queries;
    for(int i=0;i<k;i++){
        int node;
        cin>>node;
        queries.push_back(node);
        if(level[node] > maxLevel){
            maxLevel=level[node];
            lowerNode=node;
        }
    }
    //LCA from each node to lower node should be <=1 dist away from both node 
    bool flag=true;
    for(int i=0;i<k;i++){
        int L = lca(lowerNode,queries[i]);

        if(abs(level[L]-level[queries[i]]) > 1) {
            flag=false;
            break;
        }
    }
    if(flag==true) cout<<"YES\n";
    else cout<<"NO\n";
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
