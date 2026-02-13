#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

struct DSU {
   vector<int> p, sz;
   DSU(int n=0) { init(n); }
   void init(int n){
      p.resize(n);
      sz.assign(n,1);
      iota(p.begin(),p.end(),0);
   }
   int find(int x){
      if(p[x]==x) return x;
      return p[x]=find(p[x]);
   }
   bool unite(int a,int b){
      a=find(a); b=find(b);
      if(a==b) return false;
      if(sz[a]<sz[b]) swap(a,b);
      p[b]=a;
      sz[a]+=sz[b];
      return true;
   }
};

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   set<int> set;
   int count=0;
   DSU dsu(n+1);
   vector<pii> ans;
   for(int i=n-1;i>=0;i--){
    auto ub=set.upper_bound(v[i]);
    if(ub==set.end()) set.insert(v[i]);
    else{
        vector<int> temp;
        while(ub!=set.end()){
            int u=v[i],v=*ub;
            temp.pb(v);
            if(dsu.find(u)!=dsu.find(v))
            {
                ans.pb({u,v});
                count++;
                dsu.unite(u,v);
            }
            ub++;
            if(count==n-1){
                break;
            }
        }
        for(auto it : temp) set.erase(set.find(it));
        set.insert(v[i]);
        if(count==n-1) break;
    }
   }
   if(count<n-1){
    cout<<"No"<<endl;
   }else{
    cout<<"Yes"<<endl;
    for(auto [u,v] : ans) cout<<u<<" "<<v<<endl;
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
   while(t--){
       solve();
   }

   return 0;
}
