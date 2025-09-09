#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int k,x;
   cin>>k>>x;
   int a=x;
   int b=(1LL<<(k+1))-x;
   vector<int> ans;
    while (a != b) {
        if (a < b) {
            ans.push_back(1);
            b -= a;
            a <<= 1;
        }
         else {
            ans.push_back(2);
            a -= b;
            b <<= 1;
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
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
