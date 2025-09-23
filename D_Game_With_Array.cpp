#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,k;
   cin>>n>>k;
   if(k<2*n){
    cout<<"NO"<<endl;
    return;
   }
   vector<int> v(n,1);
   v[n-1]=k-n+1;
   cout<<"YES"<<endl;
   for(auto it : v) cout<<it<<" ";
   cout<<endl;
   cout<<n<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
