#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   int even=0,odd=0;
   int oddMin=1e10,evenMax=INT_MIN;
   int idx1=-1,idx2=-1;
   for(int i=0;i<n;i++) cin>>v[i];
   if(n==1) {
    cout<<v[0]<<endl;
    return;
   }
   if(n==2){
    if(v[0]>v[1]) cout<<v[0]-v[1]<<endl;
    else if(v[0]<v[1]) cout<<v[1]-v[0]+1<<endl;
    else cout<<1<<endl;
    return;
   }
   int ans = 0;
    int mx2 = -1e18, mn1 = 1e18;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            ans -= v[i];
            mx = max(mx, 2 * v[i] + i - mn1);
            mx2 = max(mx2, 2 * v[i] - i);
        } else {
            ans += v[i];
            mn1 = min(mn1, 2 * v[i] + i);
            mx = max(mx, mx2 - 2 * v[i] + i);
        }
    } // n
    if (n % 2) {
        mx = max(mx, n - 1);
    } else {
        mx = max(mx, n - 2);
    }
    ans += mx;
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
