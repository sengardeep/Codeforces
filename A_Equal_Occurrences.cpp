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
   map<int,int> map;
   vector<int> v;
   for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    map[x]++;
   }
   for(auto [num,f] : map)  v.pb(f);
   sort(begin(v),end(v));
   int ans=0;
   int m=v.size();
   for(int i=0;i<m;i++){
    int rem = m-i;
    ans = max(ans,v[i]*rem);
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
