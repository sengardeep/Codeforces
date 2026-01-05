#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(k,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) dp[k-1][i]=1;
    for(int i=k-2;i>=0;i--){
        for(int j=1;j<=n;j++) dp[i][1]=(dp[i][1]+dp[i+1][j])%mod;
        for(int j=2;j<=n;j++){
            for(int k=j;k<=n;k+=j){
                dp[i][j]=(dp[i][j]+dp[i+1][k])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+dp[0][i])%mod;
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}