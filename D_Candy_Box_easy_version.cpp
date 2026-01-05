#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(x) begin(x),end(x)

void solve() {
   int n;
   cin>>n;
   map<int,int> map;
   for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    map[x]+=1;
   }
   vector<int> v;
   for(auto [x,f] : map) v.pb(f);
   map.clear();
   for(auto it : v) map[it]++;
   sort(all(v));
   int ans=0,curr=1e9;
   for(int i=v.size()-1;i>=0;i--){
    if(curr>=v[i]){
        ans+=v[i];
        curr=v[i]-1;
    }else{
        curr=max(0LL,curr);
        ans+=curr;
        curr--;
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
