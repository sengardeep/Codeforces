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
   int st=0;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    st=x;
    map[x]++;
   }
   int ans=0;
   vector<pii> res;
   for(int i=1;i<=n;i++){
    if(map.count(i)) continue;
    else {
        ans++;
        res.pb({st,i});
    }
   }
   cout<<ans<<endl;
   for(auto [u,v] : res) cout<<u<<" "<<v<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
