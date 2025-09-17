#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> color(n+1,-1);
    vector<bool> vis(n+1,false); 
    bool flag=false;
    function<void(int)> dfs=[&](int node)->void{
        vis[node]=true;
        for(auto child : adj[node]){
            if(color[child]==color[node]){
                flag=true;
                return;
            }
            if(vis[child]) continue;
            color[child]=color[node]^1;
            dfs(child);
        }
    };
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            color[i]=0;
            dfs(i);
            if(flag){
                cout<<"Suspicious bugs found!"<<endl;
                return;
            }
        }
    }
    cout<<"No suspicious bugs found!"<<endl;
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
   for(int i=1;i<=t;i++){
       cout<<"Scenario #"<<i<<":"<<endl;
       solve();
   }

   return 0;
}