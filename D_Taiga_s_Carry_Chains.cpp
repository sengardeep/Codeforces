#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a;
    for(int i=0;i<=31;i++){
        if(n&(1LL<<i)) a.pb(i);
    }
    if(a.size()<=1){
        cout<<k<<endl;
        return;
    }
    vector<int> gaps;
    for(int i=0;i<a.size()-1;i++){
        gaps.pb(a[i+1]-a[i]-1);
    }
    vector<vector<vector<int>>> dp(gaps.size(),vector<vector<int>>(gaps.size()+1,vector<int>(2,1e9)));
    dp[0][0][0]=0;
    dp[0][1][1]=gaps[0]+1;

    for(int i=1;i<gaps.size();i++){
        for(int j=0;j<=i+1;j++){
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
            if(j==0) continue;
            if(dp[i-1][j-1][0] != 1e9) dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][0]+gaps[i]+1);
            if(dp[i-1][j-1][1] != 1e9) dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][1]+gaps[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=gaps.size();i++){
        if(min(dp[gaps.size()-1][i][0],dp[gaps.size()-1][i][1]) <= k) ans=i;
    }
    cout<<k+ans<<endl;
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
