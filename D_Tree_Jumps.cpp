#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[i].pb(x);
    adj[x].pb(i);
   }
   vector<int> ans(n+1);
   ans[1]=1;
   queue<pii> q;
   int prev=0;
   for(auto child : adj[1])
   {
       ans[child]=1;
       prev++;
       q.push({child,1});
   }
   while(!q.empty())
   {
    int s=q.size();
    int curr=0;
    for(int i=0;i<s;i++){
        int node=q.front().first,par=q.front().second;
        q.pop();
        for(auto child : adj[node]){
            if(child==par) continue;
            ans[child] = (ans[child] + (prev-ans[node]+mod)%mod)%mod;
            curr+=ans[child];
            q.push({child,node});
        }
    }
    prev=curr;
   }
   int res=0;
   for(auto it : ans) res = (res+it)%mod;
   cout<<res<<endl;
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
