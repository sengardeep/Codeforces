#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int x,y,k;
   cin>>x>>y>>k;
   int n=1e12;
   for(int i=0;i<x;i++){
    int rem=n/y;
    if(rem==0) break;
    n-=rem;
   }
   if(k>n){
    cout<<-1<<endl;
    return;
   }
   int ans=k;
   for(int i=0;i<x;i++){
    int add=(ans-1)/(y-1);
    if(add==0) break;
    ans+=add;
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
