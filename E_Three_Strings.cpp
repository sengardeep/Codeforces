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
   string s,t,a;
   cin>>s>>t>>a;
   int n=s.size(),m=t.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
   for(int i=0;i<=n;i++) dp[i][0]=0;
   for(int j=0;j<=m;j++) dp[0][j]=0;
   for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        if(i==0&&j==0) continue;
        dp[i][j]=1e9;
        if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i-1]!=a[i+j-1]));
        if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+(t[j-1]!=a[i+j-1])); 
    }
   }
   cout<<dp[n][m]<<endl;
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
