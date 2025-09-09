#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];

   sort(begin(v),end(v));
   reverse(begin(v),end(v));
   int ans=0;
   for(int i=0;i<n;i++){
    if(m==0) break;
    ans += v[i]*m;
    m--;
   }
   cout<<ans<<endl;
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
