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
   vector<int> dp(n); //dp[i] : sum of all LDS till i
   dp[0]=1;
   for(int i=1;i<n;i++){
    if(v[i]>v[i-1]) dp[i]=dp[i-1]+1;
    else dp[i]=dp[i-1]+i+1;
   }
   int ans=0;
   for(auto it : dp) ans+=it;
   cout<<ans<<endl;
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
