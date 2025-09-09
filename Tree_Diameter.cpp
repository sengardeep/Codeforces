#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=1;i<n;i++) {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   vector<int> path(n+1);
   function<void(int,int)> dfs = [&](int node,int par)->void{
    for(auto child : adj[node]){
        if(child!=par){
            path[child] = path[node]+1;
            dfs(child,node);
        }
    }
   };
   dfs(1,0);
   int lastNode = 1;
   for(int i=1;i<n+1;i++) if(path[i]>path[lastNode]) lastNode=i;
   path.assign(n+1,0);
   dfs(lastNode,0);
   cout<<*max_element(begin(path),end(path));

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
