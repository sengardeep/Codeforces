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
   int n,b,c;
   cin>>n>>b>>c;
   if(c>=n){
    cout<<n<<endl;
    return;
   }
   if(!b){
    if(c<n-2) cout<<-1<<endl;
    else cout<<n-1<<endl;
    return;
   }
   int k=(n-1-c)/b+1;
   if(k>n) k=n;
   cout<<n-k<<endl;
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
