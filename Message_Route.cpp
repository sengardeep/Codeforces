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
   vector<int> adj[n+1];
   for(int i=0;i<m;i++) {
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vector<bool> vis(n+1,false);
   queue<int> q;
   vis[1]=true;
   q.push(1);
   vector<int> par(n+1,-1);
   while(!q.empty()){
    int node=q.front();
    if(node==n) break;
    q.pop();
    for(auto child : adj[node]){
        if(vis[child]) continue;
        par[child]=node;
        vis[child]=true;
        q.push(child);
    }
   }
   if(par[n] == -1) cout<<"IMPOSSIBLE";
   else{
    vector<int> ans;
    ans.pb(n);
    int i=n;
    while(par[i] != -1){
        i=par[i];
        ans.pb(i);
    }
    reverse(begin(ans),end(ans));
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it<<" ";
   }
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
