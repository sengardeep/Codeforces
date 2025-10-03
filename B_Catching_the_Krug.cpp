#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;
    int ans = 0;
    int tk_r0 = rK;
    int td_r0 = max(abs(0 - rD), abs(cK - cD));
    if (tk_r0 < td_r0) ans = max(ans, td_r0);
    int tk_rn = n - rK;
    int td_rn = max(abs(n - rD), abs(cK - cD));
    if (tk_rn < td_rn) ans = max(ans, td_rn);
    int tk_c0 = cK;
    int td_c0 = max(abs(rK - rD), abs(0 - cD));
    if (tk_c0 < td_c0) ans = max(ans, td_c0);
    int tk_cn = n - cK;
    int td_cn = max(abs(rK - rD), abs(n - cD));
    if (tk_cn < td_cn) ans = max(ans, td_cn);
    cout << ans << endl;
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
