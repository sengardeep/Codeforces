#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n,a,b;
   cin>>n>>a>>b;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   //parity of two number's xor and sum would be same
   int flag=(a%2);
   for(int i=0;i<n;i++) 
   {
       flag=(a+v[i])%2;
       a+=v[i];
   }

   if(flag == (b%2)) cout<<"Alice"<<endl;
   else cout<<"Bob"<<endl;
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
