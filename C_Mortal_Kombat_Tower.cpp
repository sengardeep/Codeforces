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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<vector<int>> dp(n,vector<int>(2,-1));
   function<int(int,int)> helper=[&](int index,int flag)->int{
    if(index>=n) return 0;
    if(dp[index][flag]!=-1) return dp[index][flag];
    int ans=0;
    if(flag){
        ans=v[index]+helper(index+1,flag^1);
        if(index+1<n) ans=min(ans,v[index]+v[index+1]+helper(index+2,flag^1));
    }else{
        ans=min(helper(index+1,flag^1),helper(index+2,flag^1));
    }
    return dp[index][flag]=ans;
   };
   cout<<helper(0,1)<<endl;
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
