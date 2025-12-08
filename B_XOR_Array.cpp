#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,l,r;
   cin>>n>>l>>r;
   --l;
   --r;
   vector<int> v(n);
   for(int i=0;i<n;i++) v[i]=i+1;
   if(l>0) v[r]=v[l-1];
   else v[r]=0;
   vector<int> ans(n);
   ans[0]=v[0];
   for(int i=1;i<n;i++) ans[i]=v[i-1]^v[i];
   for(auto it : ans) cout<<it<<" ";
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
