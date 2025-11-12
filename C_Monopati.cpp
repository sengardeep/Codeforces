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
    vector<int> a{0},b{0};
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.pb(x);
    }
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        b.pb(x);
    }
    vector<int> mn1(n+1), mx1(n+1);
    mn1[1] = mx1[1] = a[1];
    for (int i = 2; i <= n; i++) {
        mn1[i] = min(mn1[i - 1], a[i]);
        mx1[i] = max(mx1[i - 1], a[i]);
    }
    vector<int> mn2(n + 2), mx2(n + 2);
    mn2[n] = mx2[n] = b[n];   
    for (int i = n - 1; i >= 1; i--) {
        mn2[i] = min(mn2[i + 1], b[i]);
        mx2[i] = max(mx2[i + 1], b[i]);
    }
    int x = 2 * n;
    vector<int> v(x + 2, 1e18);
    for (int k = 1; k <= n; k++) {
        int mn = min(mn1[k], mn2[k]);
        int mx = max(mx1[k], mx2[k]);
        if (mn >= 1 && mn <= x && mx < v[mn]) v[mn] = mx;
    }

    int ans = 0,curr = 1e18;
    for (int i = x; i >= 1; i--) {
        if (v[i] != 1e18) curr = min(curr, v[i]);
        if (curr != 1e18) ans += (x - curr + 1);
    }
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
