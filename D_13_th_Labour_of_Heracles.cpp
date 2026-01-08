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
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> deg(n);
   for(int i=0;i<n-1;i++){
       int u,x;
       cin>>u>>x;
       --u;
       --x;
       deg[u]++;
       deg[x]++;
    }
    priority_queue<pii> pq;
    for(int i=0;i<n;i++) 
    {
        if(deg[i]>1)
        pq.push({v[i],deg[i]});
    }
    int ans=0;
    for(auto it : v) ans+=it;
    cout<<ans<<" ";
    for(int i=1;i<n-1;i++){
        auto [x,d] = pq.top();
        pq.pop();
        ans+=x;
        d--;
        if(d>1)
        pq.push({x,d});
        cout<<ans<<" ";
    }
    cout<<endl;
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
