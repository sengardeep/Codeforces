#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   string s;
   cin>>s;
   int n=s.size();
   vector<int> parent(n),sz(n,1);
   iota(begin(parent),end(parent),0);
   function<int(int)> findPar = [&](int node)->int{
    if(parent[node]==node) return node;
    return parent[node]=findPar(parent[node]);
   };
   auto unite = [&](int u,int v)->void{
    int pu=findPar(u),pv=findPar(v);
    if(sz[pu]>sz[pv]){
        sz[pu]+=sz[pv];
        parent[pv]=pu;
    }
    else{
        parent[pu]=pv;
        sz[pv]+=sz[pu];
    }
   };
   for(int i=1;i<n;i++){
    if(s[i]==s[i-1]) unite(i,i-1);
   }
   int q;
   cin>>q;
   while(q--){
    int type,i;
    cin>>type>>i;
    if(type==1){
        int pi=findPar(i);
        cout<<sz[pi]<<endl;
    }else{
        sz[i]=0;
        int pi=findPar(i);
        sz[pi]--;
    }
   }
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
   for(int i=1;i<=t;i++){
       cout<<"Case "<<i<<":"<<endl;
       solve();
   }

   return 0;
}
