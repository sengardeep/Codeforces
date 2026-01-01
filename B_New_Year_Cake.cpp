#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int a,b;
   cin>>a>>b;
   if(a>b) swap(a,b);
   int mx=0;
   while(a>=(1<<mx)) mx++;
   if(a==b) cout<<mx<<endl;
   else{
    if(b>=2*a) cout<<mx+1<<endl;
    else cout<<mx<<endl;
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
