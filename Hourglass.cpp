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
   int s,k,m;
   cin>>s>>k>>m;
   if(s==k) {
    int rem=m%k;
    cout<<s-rem<<endl;
   }else if(s<k){
    int rem=m%k;
    cout<<max(0LL,s-rem)<<endl;
   }else{
    int rem=m%k;
    int d=m/k;
    if(d%2){
        cout<<max(0LL,k-rem)<<endl;
    }else{
        cout<<max(0LL,s-rem)<<endl;
    }
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
