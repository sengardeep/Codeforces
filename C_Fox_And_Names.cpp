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
   vector<string> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> adj[26];
   vector<int> deg(26);
   for(int i=1;i<n;i++){
    int j=0;
    while(j<min(v[i-1].size(),v[i].size()) && v[i-1][j]==v[i][j]) j++;
    if(j==v[i].size()){
        cout<<"Impossible";
        return;
    }
    if(j<v[i-1].size()) 
    {
        adj[v[i-1][j]-'a'].pb(v[i][j]-'a');
        deg[v[i][j]-'a']++;
    }
   }
   //Kahn's Algo
   queue<int> q;
   for(int i=0;i<26;i++) if(deg[i]==0) q.push(i);
   string ans="";
   while(!q.empty()){
    int node=q.front();
    q.pop();
    ans += (node+'a');
    for(auto child : adj[node]){
        deg[child]--;
        if(deg[child]==0) q.push(child);
    }
   }
   if(ans.size()<26) cout<<"Impossible";
   else cout<<ans;
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
