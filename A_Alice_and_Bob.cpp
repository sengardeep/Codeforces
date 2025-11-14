#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,a;
   cin>>n>>a;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int ub=upper_bound(begin(v),end(v),a)-begin(v);
   int lb=lower_bound(begin(v),end(v),a)-begin(v);
   int right=n-ub;
   ub=lb;
   if(ub < n-ub){
    cout<<a+1<<endl;
   }else cout<<a-1<<endl;
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
