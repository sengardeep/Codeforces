#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
   int n;
   cin>>n;
   int sum=0,m=2*n;
   vector<pii> ans;
   for(int i=n;i>=1;i--) {
    ans.pb({1,i});
    ans.pb({2,i});
    sum+=(i*1LL*i + (i-1)*i);
   }
   cout<<sum<<" "<<m<<endl;
   for(auto it : ans){
    cout<<it.first<<" "<<it.second<<" ";
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
   }

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
