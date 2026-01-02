#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int a,b,k;
   cin>>a>>b>>k;
   vector<int> map1(a+1),map2(b+1);
   vector<pii> v(k);
   for(int i=0;i<k;i++) {
    cin>>v[i].first;
    map1[v[i].first]++;
   }
   for(int i=0;i<k;i++) {
    cin>>v[i].second;
    map2[v[i].second]++;
   }
   int ans=0;
   for(int i=0;i<k;i++){
    int b=v[i].first,g=v[i].second;
    map1[b]--;
    map2[g]--;
    ans+=(k-1-i-map1[b]-map2[g]);
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
