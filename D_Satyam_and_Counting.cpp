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
   vector<pii> v;
   map<pii,int> map;
   for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    map[{x,y}]=1;
    v.pb({x,y});
   }
   sort(v.begin(),v.end());
   int ans=0;
   for(int i=0;i<n;i++){
    if(i<n-1)
    if(v[i].first==v[i+1].first) ans+=(n-2);
    int x=v[i].first,y=v[i].second;
    if(y){
        if(map.count({x+1,y-1})&&map.count({x+2,y})) ans++;
    }
    else{
        if(map.count({x+1,y+1})&&map.count({x+2,y})) ans++;
    }
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
