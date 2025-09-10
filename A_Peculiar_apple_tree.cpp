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
   for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[i].push_back(x);
    adj[x].push_back(i);
   }
   vector<int> level(n+1);
   int l=1;
   queue<pii> q;
   q.push({1,0});
   while(!q.empty()){
    int s=q.size();
    level[l]=s;
    l++;
    while(s--){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto child : adj[node]){
            if(child==par) continue;
            q.push({child,node});
        }
    }
   }
   int ans=0;
   for(auto it : level) ans += (it&1);
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
