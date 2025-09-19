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
   map<pii,int> map;
   for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].pb({v,w});
   }
   vector<pii> cost(n+1,{1e18,1e18}); //Original,making Discount
   // priority queue: (cost, node, used)
   using T = tuple<int,int,int>;
   priority_queue<T, vector<T>, greater<T>> pq;
   cost[1] = {0,0};
   pq.push({0,1,0}); 
   while(!pq.empty()){
        auto [c,node,used] = pq.top(); pq.pop();
        if(c > (used ? cost[node].second : cost[node].first)) continue;
        for(auto [child,w] : adj[node]){
            // case 1: take edge normally
            if(c + w < (used ? cost[child].second : cost[child].first)){
                if(used) cost[child].second = c + w;
                else cost[child].first = c + w;
                pq.push({c+w,child,used});
            }
            // case 2: use coupon if not used yet
            if(!used && c + w/2 < cost[child].second){
                cost[child].second = c + w/2;
                pq.push({c+w/2,child,1});
            }
        }
    }
   cout<<cost[n].second;
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
