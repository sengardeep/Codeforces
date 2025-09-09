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
   vector<int> deg(n+1);
   for(int i=1;i<n;i++)
   {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
   }
   if(n<=2 || n<=k){
    cout<<0<<endl;
    return;
   }
   vector<int> ops(n+1,0);
   queue<pair<int,int>> q; //{node,par}
   for(int i=1;i<=n;i++) 
   {
       if(deg[i]==1) 
       {
           ops[i]=1;
        //    dbg(i);
           q.push({i,0});
       }
   }

   while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto child : adj[node]){
            if(child==par) continue;
            deg[child]--;
            if(deg[child]==1)
            {
                ops[child] = max(ops[node] + 1,ops[child]);
                q.push({child,node});
            }
        }
   }

   int ans=0;
   for(int i=1;i<=n;i++) if(ops[i]>k) ans++;

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
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}