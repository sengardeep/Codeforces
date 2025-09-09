#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> indices; //Breaking points
   indices.push_back(0);
   for(int i=1;i<n;i++) if(v[i]*2 <= v[i-1]) indices.push_back(i);
   indices.push_back(n);

   int ans=0;
   for(int i=0;i<indices.size()-1;i++){
    int l=indices[i],r=indices[i+1]-1;
    int len = (r-l+1);
    int res = (len-(k+1)+1);
    if(res > 0) ans+=res;
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
