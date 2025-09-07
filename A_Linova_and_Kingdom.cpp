#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //While We are selecting any node at any level that means we are increasing our ans by depth as well decreasing our and by subtree
    //We need to calculate top (depth-subtree)
    vector<int> arr(n),depth(n+1,-1),subtree(n+1);
    iota(begin(arr),end(arr),1);
    function<void(int,int)> dfs = [&](int node,int par)->void{
        depth[node] = depth[par]+1;
        for(auto child : adj[node]){
            if(child == par) continue;
            dfs(child,node);
            subtree[node] += subtree[child]+1;
        }
    };
    dfs(1,0);

    sort(begin(arr),end(arr),[&](int a,int b){
        return depth[a]-subtree[a] > depth[b]-subtree[b];
    });

    int ans=0;
    for(int i=0;i<k;i++) ans += depth[arr[i]]-subtree[arr[i]];

    cout<<ans;
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
