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
   vector<pii> adj[n+1];
   for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].pb({v,w});
   }
   //Dijkstra Algorithm (SSSP)
   priority_queue<pii,vector<pii>,greater<pii>> pq;
   pq.push({0,1}); //dist,node
   vector<int> dist(n+1,1e18);
   dist[1]=0;
   while(!pq.empty()){
    auto [d,node]=pq.top(); pq.pop();
    if(d > dist[node]) continue; //Critical Point(If you use visited , you'll get TLE)
    for(auto it : adj[node]){
        auto [child,w]=it;
        if(dist[child] > d + w){
            dist[child] = d+w;
            pq.push({dist[child],child});
        }
    }
   }
   for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
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
