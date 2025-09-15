#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> prev(2, 1), dp(2, 0);
    if (n == 1) {
        cout << (prev[0] + prev[1]) % mod << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        dp[0] = dp[1] = 0;
        if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
            dp[0] = (dp[0] + prev[0]) % mod;
        }
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
            dp[1] = (dp[1] + prev[0]) % mod;
        }
        if (b[i - 1] <= a[i] && a[i - 1] <= b[i]) {
            dp[0] = (dp[0] + prev[1]) % mod;
        }
        if (b[i - 1] <= b[i] && a[i-1] <= a[i]) {
            dp[1] = (dp[1] + prev[1]) % mod;
        }
        prev = dp;
    }
    cout << (prev[0] + prev[1]) % mod << endl;
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
