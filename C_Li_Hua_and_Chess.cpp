#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
   int n,m;
   cin>>n>>m;
   auto ask=[&](int r,int c){
    cout<<"? "<<r<<" "<<c<<endl;
    int ans; cin>>ans;
    return ans;
   };
   int d=ask(1,1);
   int d1=1e10,d2=1e10;
   if((1+d)<=n){
    d1=ask(1+d,1);
   }
   if((1+d)<=m){
    d2=ask(1,1+d);
   }
   if(d1<d2){
    cout<<"! "<<(1+d)<<" "<<(1+d1)<<endl;
    return;
   }else{
    cout<<"! "<<(1+d2)<<" "<<(1+d)<<endl;
    return;
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
