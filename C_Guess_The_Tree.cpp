#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void solve() {
   int n;
   cin>>n;
   DSU dsu(n);
   auto ask=[&](int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int ans; cin>>ans;
    return ans;
   };
   vector<pii> ans;
   function<void(int,int)> helper=[&](int a,int b)->void{
    int x=ask(a,b);
    if(x==a) {
        ans.pb({a,b});
        dsu.unite(a,b);
        return;
    }
    if(dsu.find(a)!=dsu.find(x)){
        helper(a,x);
    }
    if(dsu.find(b)!=dsu.find(x)){
        helper(x,b);
    }
   };
   for(int i=2;i<=n;i++){
    if(dsu.find(1)!=dsu.find(i)){
        helper(1,i);
    }
   }
   cout<<"! ";
   for(auto [a,b] : ans) cout<<a<<" "<<b<<" ";
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
