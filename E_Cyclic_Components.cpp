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
   int ans=0;
   vector<int> parent(n+1,0),rank(n+1,1);
   iota(parent.begin(),parent.end(),0);
   function<int(int)> find=[&](int node)->int{
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
   };
   auto unite=[&](int u,int v){
    int pu=find(u);
    int pv=find(v);
    if(pu==pv) return;
    if(rank[pu] < rank[pv]) swap(pu,pv);
    parent[pv]=pu;
    if(rank[pu] == rank[pv]) rank[pu]++;
   };
   vector<int> vis(n+1,0);
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    int pu=find(u),pv=find(v);
    if(pu==pv){
        if(vis[pu]==1){
            vis[pu]++;
            ans--;
        }
        else if(vis[pu]>1) continue;
        else {
            vis[pu]++;
            ans++;
        }
    }
    else{
        unite(u,v);
    }
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
