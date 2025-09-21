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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   sort(begin(v),end(v));
   int x=v[n-1];
   int ans1=0;
   for(int i=0;i<n-1;i++)
   {
    if(v[i]+v[i+1] <= x) ans1++;
   }
   int ans2=0;
   x=v[0];
   for(int i=n-1;i>1;i--)
   {
    if(v[0]+v[1] <= v[i]) ans2++; 
   }
   cout<<min(ans1,ans2)<<endl;
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
