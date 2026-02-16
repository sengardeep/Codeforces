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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> ans(n);
   for(int i=1;i<n-1;i++){
    ans[i]=(v[i-1]+v[i+1]-2*v[i])/2;
   }
   int x=0,y=0;
   for(int i=1;i<n-1;i++) {
    x+=(ans[i]*i);
    y+=(ans[i]*(n-1-i));
   }
   ans[n-1]=(v[0]-x)/(n-1);
   ans[0]=(v[n-1]-y)/(n-1);

   for(auto x : ans) cout<<x<<" ";
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
