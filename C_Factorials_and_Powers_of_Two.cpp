#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

vector<int> v;
void solve() {
   int n;
   cin>>n;
   int s=v.size();
//    for(auto it : v) cerr<<it<<" ";
   map<pii,int> dp;
   function<int(int,int)> helper=[&](int index,int rem)->int{
    if(rem==0) return 0;
    if(index==s) return __builtin_popcountll(rem);
    auto key=make_pair(index,rem);
    if(dp.count(key)) return dp[key];
    int ans=helper(index+1,rem);
    if(rem>=v[index]) ans=min({ans,1+helper(index+1,rem-v[index])});
    return dp[key]=ans;
   };
   int ans=helper(0,n);
   if(ans>=1e9) ans=-1;
   cout<<ans<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int f=1;
   for(int i=1;i<=14;i++){
    f*=i;
    v.pb(f);
   }
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
