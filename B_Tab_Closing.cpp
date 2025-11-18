#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   double a,b,n;
   cin>>a>>b>>n;
   if(a==b && (a/n)<=b){
    cout<<1<<endl;
    return;
   } 
   double f=min(b,a/n);
   int ans=1;
   n--;
   double s=min(b,a/n);
   if(f!=s) ans++;
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
