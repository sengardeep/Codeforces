#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];


   vector<int> parent(n+1,0);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    parent[node]=par;
    for(auto child : adj[node]){
        if(child == par) continue;
        dfs(child,node);
    }
   };
   dfs(1,0);

   int i=0,j=1;
   while(j<n && i<n){
    if(v[i]==parent[v[j]]) j++;
    else i++;
   }
   if(j==n)
   cout<<"Yes"<<endl;
   else 
   cout<<"No"<<endl;
//    for(int i=0;i<n;i++) cerr<<level[v[i]]<<" ";
//    for(int i=0;i<n-1;i++){
//     if(level[v[i]]!=level[v[i+1]]){
//         if(level[v[i+1]]-level[v[i]] != 1){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
// }
// cout<<"Yes"<<endl;
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
