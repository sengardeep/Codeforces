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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    for(int i=1;i<n;i++){
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}