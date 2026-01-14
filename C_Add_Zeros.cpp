#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
   int n;
   cin>>n;
   map<int,vector<int>> mp;
   for(int i=0;i<n;i++) {
       int x;
       cin>>x;
       if(i!=0)
    mp[x+i].pb(x+2*i);
   }
   map<int,int> dp;
   function<int(int)> dfs=[&](int x)->int{
    if(dp.count(x)) return dp[x];
    int ans=x;
    for(auto i : mp[x]) ans=max(ans,dfs(i));
    return dp[x]=ans;
   };
   cout<<dfs(n)<<endl;
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
