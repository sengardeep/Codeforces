#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

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
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];

        vector<int> dp(n+1,-1),mx(n+1,-1e16);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i-1],i+mx[v[i]]);
            mx[v[i]]=max(mx[v[i]],dp[i-1]-(i-1));
        }

        cout<<dp[n]<<endl;
    }

    return 0;
}
