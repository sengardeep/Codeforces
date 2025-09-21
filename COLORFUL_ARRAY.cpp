#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,q;
   cin>>n>>q;
   using T = tuple<int,int,int>;
   vector<T> query;
   while(q--){
    int i,j,c;
    cin>>i>>j>>c;
    query.pb({i,j,c});
   }
   reverse(begin(query),end(query));
   vector<int> parent(n+2,0);
   vector<int> ans(n+1,0);
   function<int(int)> findPar=[&](int u)->int{
    if(parent[u]==u) return u;
    return parent[u]=findPar(parent[u]);
   };
   iota(parent.begin(),parent.end(),0);
   for(auto [i,j,c] : query){
    while(i<=j){
        int p = findPar(i);
        if(p<=j){
            ans[p]=c;
            parent[p]=p+1;
            i=parent[p];
        }
        else break;
    }
   }
   for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
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
