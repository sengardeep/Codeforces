#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> cats(n+1);
    vector<int> adj[n+1];
    for(int i=1;i<=n;i++) cin>>cats[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    function<int(int,int,int)> dfs = [&](int node,int par,int k)->int{
        if(cats[node]==false) k=m;
        if(k==0 && cats[node]) return 0;
        int ans=0;
        bool isLeaf=true;
        for(auto child : adj[node]){
            if(child==par) continue;
            isLeaf=false;
            if(cats[node]) ans += dfs(child,node,k-1);
            else ans += dfs(child,node,k);
            // dbg(ans);
        }
        if(isLeaf) return 1;
        return ans;
    };

    cout<<dfs(1,0,m);
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
