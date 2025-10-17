#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int> pre(n,0);
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    --u;
    --v;
    pre[u]++;
    if(v+1<n) pre[v+1]--;
   }
   for(int i=1;i<n;i++) pre[i]+=pre[i-1];
   map<int,vector<int>> map;
   for(int i=0;i<n;i++) map[pre[i]].pb(i);
   vector<int> ans(n);
   int st=n-1;
   for(auto [num,v] : map){
    for(auto it : v) ans[it]=st--;
   }
   for(auto it : ans) cout<<it<<" ";
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
