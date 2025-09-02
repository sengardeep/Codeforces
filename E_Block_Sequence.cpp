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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> dp(n+1,INT_MAX); //dp[i]:min ops required after ith index
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            if(i+v[i]+1>n) dp[i]=dp[i+1]+1;
            else{
                dp[i]=min(1+dp[i+1],dp[i+v[i]+1]);
            }
        }

        cout<<dp[0]<<endl;

    }

    return 0;
}
