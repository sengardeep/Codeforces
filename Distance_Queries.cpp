#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
long long binpow(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void solve() {
   int n,q;
   cin>>n>>q;
   vector<int> adj[n+1];
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   //Binary Lifting
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
   while(q--){
    int a,b;
    cin>>a>>b;
    int ans = abs(level[a]-level[b]);
    // dbg(ans);
    if(level[a] > level[b]) swap(a,b);
    b=findKthPar(b,ans);
    // dbg(a);
    // dbg(b);
    if(a==b) 
    {
        cout<<ans<<endl;
        continue;
    }
    for(int i=18;i>=0;i--){
        if(dp[a][i] != dp[b][i]){
            int temp = binpow(2,i);
            ans += 2*temp;
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    ans += 2;
    cout<<ans<<endl;
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
