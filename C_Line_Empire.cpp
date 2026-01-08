#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,a,b;
   cin>>n>>a>>b;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int total=0;
   vector<int> pre(n);
   for(int i=0;i<n;i++)
   {
       total+=(v[i]*b);
       pre[i]=(v[i]*b);
   }
   for(int i=1;i<n;i++) pre[i]+=pre[i-1];
   int ans=total;
   for(int i=0;i<n;i++) 
   {
    int minus=v[i]*b*(n-i-1);
    int plus=v[i]*a;
    int extra=(i>0?pre[i-1]:0);
    // dbg(minus);
    // dbg(plus);
    // dbg(extra);
    ans=min(ans,total-minus+plus-extra);
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
