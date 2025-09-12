#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<vector<int>> adj(n+1);
   for(int i=1;i<n;i++) {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }  
   vector<int> indp(n+1,0); //Max subtree height 
   vector<int> outdp(n+1,0); //Max distance we can get by making Root i
   function<void(int,int)> indfs=[&](int node,int par)->void{
      for(auto child : adj[node]){
         if(child==par) continue;
         indfs(child,node);
         indp[node]=max(indp[child]+1,indp[node]);
      }
   };
   indfs(1,0);
   function<void(int,int)> outdfs=[&](int node,int par)->void{
      int mx1=-1,mx2=-1,maxChild=0;
      for(auto child : adj[node]){
         if(child==par) continue;
         int val = 1 + indp[child];
         if(val >= mx1){
            mx2 = mx1;
            mx1 = val;
            maxChild = child;
         }else if(val > mx2){
            mx2 = val;
         }
      }
      for(auto child : adj[node]){
         if(child==par) continue;
         int largest = mx1;
         if(maxChild==child) largest=mx2;
         outdp[child]=1+max(outdp[node],largest);
         outdfs(child,node);
      }
   };
   outdfs(1,0);
   for(int i=1;i<=n;i++) cout<<max(indp[i],outdp[i])<<" ";
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
