#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
   int n,k;
   cin>>n>>k;
   vector<int> adj[n];
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    --u;--v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   int cnt=0;
   function<int(int,int,int)> helper=[&](int x,int node,int par){
    int ans=1;
    for(auto child : adj[node]){
        if(child!=par){
            ans+=helper(x,child,node);
        }
    }
    if(ans>=x){
        cnt++;
        ans=0;
    }
    return ans;
   };
   int start=1,end=n;
   int x=1;
   while(start<=end){
    int mid=(start+end)/2;
    cnt=0;
    helper(mid,0,-1);
    if(cnt>k){
        x=mid;
        start=mid+1;
    }else end=mid-1;
   }
   cout<<x<<endl;
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
