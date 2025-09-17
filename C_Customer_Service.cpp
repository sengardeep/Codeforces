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
   vector<vector<int>> v(n,vector<int>(n));
   for(int i=0;i<n;i++)
   for(int j=0;j<n;j++) cin>>v[i][j];
   vector<int> ones(n); //Count trailing ones at each level
   for(int i=0;i<n;i++){
    int count=0;
    for(int j=n-1;j>=0;j--){
        if(v[i][j]==1) count++;
        else break;
    }
    ones[i]=count;
   }
   sort(begin(ones),end(ones));
   int ans=0;
   for(int i=0;i<n;i++) {
    if(ans<=ones[i]) ans++;
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
