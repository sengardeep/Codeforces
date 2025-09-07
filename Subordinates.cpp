#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[x].push_back(i);
    // adj[i].push_back(x);
   }
   vector<int> dp(n+1,-1); 

   function<int(int)> dfs = [&](int node)->int{
       if(dp[node] != -1) return dp[node];
        int ans=1;
        for(auto child : adj[node]){
            ans += dfs(child);
        }
        return dp[node]=ans;
   }; 

   for(int i=1;i<=n;i++) cout<<dfs(i)-1<<" ";
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
