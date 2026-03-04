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
   vector<int> v(n),pos(n+1);
   for(int i=0;i<n;i++) 
   {
       cin>>v[i];
       pos[v[i]]=i;
   }
   vector<int> vis(n+1,1);
   int ans=0;
   for(int i=1;i<=n;i++){
    int idx=pos[i];
    int left=0,right=0;
    for(int j=0;j<idx;j++) left+=vis[j];
    for(int j=idx+1;j<n;j++) right+=vis[j];
    ans+=min(left,right);
    vis[idx]=0;
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
