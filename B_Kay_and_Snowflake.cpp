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
   vector<int> adj[n+1];
   for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[i].pb(x);
    adj[x].pb(i);
   }
   static bool built = false;
   static vector<int> par, sz, heavy, cent;
   if (!built) {
       par.assign(n + 1, 0);
       sz.assign(n + 1, 0);
       heavy.assign(n + 1, -1);
       cent.assign(n + 1, 0);

       function<void(int,int)> dfs1 = [&](int x, int p) {
           par[x] = p;
           sz[x] = 1;
           int mx = 0;
           for (int v : adj[x]) if (v != p) {
               dfs1(v, x);
               sz[x] += sz[v];
               if (sz[v] > mx) { mx = sz[v]; heavy[x] = v; }
           }
       };
       dfs1(1, 0);

       function<void(int)> dfs2 = [&](int x) {
           if (heavy[x] == -1) {
               cent[x] = x;
           } else {
               dfs2(heavy[x]);
               int c = cent[heavy[x]];
               int half = sz[x] / 2;
               while (sz[x] - sz[c] > half) c = par[c];
               cent[x] = c;
           }
           for (int v : adj[x]) if (v != par[x] && v != heavy[x]) dfs2(v);
       };
       dfs2(1);

       built = true;
   }
   while(q--){
    int u;

    cin >> u;
    cout << cent[u] << endl;
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
