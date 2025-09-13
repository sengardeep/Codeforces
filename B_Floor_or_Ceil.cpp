#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int x, fllor, ceil;
    cin >> x >> fllor >> ceil;
 
    auto F = [&](int x, int n) {
        while (n--) {
            if (!x) return 0LL;
            x >>= 1;
        }
        return x;
    };
 
    auto C = [&](int x, int n) {
        while (n--) {
            if (x <= 1) return x;
            x = (x + 1) >> 1;
        }
        return x;
    };
 
    int case1 = C(F(x, fllor), ceil); 
    int case2 = F(C(x, ceil), fllor); 
 
    int mini = min(case1, case2);
    int maxi = max(case1, case2);
 
    cout << mini << " " << maxi << "\n";
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
