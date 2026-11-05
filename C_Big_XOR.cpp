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
   int log = floor(log2(n))+1;
   vector<int> v(n+1);
   iota(begin(v),end(v),0);
   for(int i=log;i>=1;i--){
    int cnt = 0;
    for(int x : v) if((x&(1<<i))) cnt++;
    if(cnt%2) continue;
    else {
        v[(1<<(i-1))]*=2;
    }
   }
//    int m=0,k=0;
   for(int i=1;i<=n;i++){
    // m^=v[i];
    // k|=i;
    if(i==v[i]) cout<<0<<" ";
    else cout<<1<<" ";
   }
//    dbg(k);
//    dbg(m);
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
