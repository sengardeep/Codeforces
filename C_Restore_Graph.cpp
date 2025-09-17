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
   vector<int> dist(n+1);
   map<int,vector<int>> map;
   int maxDist=0;
   for(int i=1;i<=n;i++)
   {
       cin>>dist[i];
       maxDist=max(maxDist,dist[i]);
       map[dist[i]].pb(i);
   }
   if(map[0].size()!=1){
    cout<<-1<<endl;
    return;
   }
   vector<pii> ans;
   vector<int> prev;
   prev.pb(map[0].back());
   for(int i=1;i<=maxDist;i++){
    vector<int> curr=map[i];
    int j=0,p=prev.size();
    if(p==0){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<curr.size();i++){
        ans.pb({prev[j],curr[i]});
        j = (j+1)%p;
    }
    prev=curr;
   }
   vector<int> deg(n+1);
   for(auto [u,v] : ans){
    deg[u]++;
    deg[v]++;
   }
   for(int i=1;i<=n;i++) {
    if(!deg[i] || deg[i]>k){
        cout<<-1<<endl;
        return;
    }
   }
   cout<<ans.size()<<endl;
   for(auto [u,v] : ans) cout<<u<<" "<<v<<endl;
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
