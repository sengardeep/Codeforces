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
   int n,k;
   cin>>n>>k;
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   vector<vector<int>> dp(n,vector<int>(2,0));
   dp[0][0]=a[0];
   dp[0][1]=b[0]+a[0];
   int mxE=dp[0][0],mxO=dp[0][1];
   for(int i=1;i<n;i++){
    dp[i][0]=max(a[i],dp[i-1][0]+a[i]);
    dp[i][1]=max({a[i]+b[i],dp[i-1][0]+a[i]+b[i],dp[i-1][1]+a[i]});
    mxE=max(mxE,dp[i][0]);
    mxO=max(mxO,dp[i][1]);
   }
   if(k%2) cout<<mxO<<endl;
   else cout<<mxE<<endl;
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
