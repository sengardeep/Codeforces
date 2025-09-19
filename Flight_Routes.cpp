#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,m,k;
   cin>>n>>m>>k;
   vector<pii> adj[n+1];
   for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].pb({v,w});
   }
   //Dijkstra Algorithm (SSSP)
   priority_queue<pii,vector<pii>,greater<pii>> pq;
   pq.push({0,1}); //dist,node
   vector<priority_queue<int>> dist(n+1);
   //Instead of creating one value for every node , we can create k values for each node
   dist[1].push(0);
   while(!pq.empty()){
    auto [d,node]=pq.top();pq.pop();
    if(dist[node].size()==k && dist[node].top()<d) continue;
    for(auto it : adj[node]){
        auto [child,w]=it;
        if(dist[child].size()<k){
            dist[child].push(d+w);
            pq.push({d+w,child});
        }
        else if(dist[child].top() > d+w){
            dist[child].pop();
            dist[child].push(d+w);
            pq.push({d+w,child});
        }
    }
   }
   vector<int> ans;
   while(!dist[n].empty()){
    ans.pb(dist[n].top());
    dist[n].pop();
   }
   sort(begin(ans),end(ans));
   for(auto it : ans) cout<<it<<" ";
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
