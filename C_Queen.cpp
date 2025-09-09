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
   vector<int> c(n+1);
   int root=-1;
   for(int i=1;i<=n;i++){
    int p,x;
    cin>>p>>x;
    if(p!=-1){
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    else root=i;
    c[i]=x;
   }
   vector<int> canRemove(n+1,0);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    int ans=c[node];
    for(auto child : adj[node]){
        if(child == par) continue;
        ans &= c[child];
        dfs(child,node);
    }
    canRemove[node]=ans;
   };
   dfs(root,-1);
   vector<int> ans;
   for(int i=1;i<=n;i++) {
    if(c[i] && canRemove[i]) ans.push_back(i);
   }
   if(ans.empty()) cout<<-1<<endl;
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
