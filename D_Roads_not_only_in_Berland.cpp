#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
struct DSU {
    vector<int> parent, size, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        iota(begin(parent), end(parent), 0); // parent[i] = i
    }
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }
    void unionSize(int a, int b) {
        int pa = findPar(a), pb = findPar(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
    void unionRank(int a, int b) {
        int pa = findPar(a), pb = findPar(b);
        if (pa == pb) return;
        if (rank[pa] == rank[pb]) {
            parent[pa] = pb;
            rank[pb]++;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }
};
void solve() {
   int n;
   cin>>n;
   vector<pii> close;
   DSU d(n);
   for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    if(d.findPar(u)==d.findPar(v)){
        close.pb({u,v});
    }
    else {
        d.unionRank(u,v);
    }
   }
   if(close.empty()){
       cout<<0<<endl;
       return;
    }
    vector<pii> opens;
    for(int i=2;i<=n;i++) {
        if(d.findPar(1) != d.findPar(i)){
            d.unionRank(1,i);
            opens.pb({1,i});
        }
    }
    cout<<opens.size()<<endl;
   for(int i=0;i<opens.size();i++){
    cout<<close[i].first<<" "<<close[i].second<<" ";
    cout<<opens[i].first<<" "<<opens[i].second<<endl;
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
