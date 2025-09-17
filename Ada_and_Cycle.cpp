#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    const int MAXN = 2005;
    int n; cin >> n;

    vector<bitset<MAXN>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (x) adj[i].set(j);
        }
    }

    for (int s = 0; s < n; ++s) {
        bitset<MAXN> vis, cur = adj[s];
        int len = 1;
        bool found = false;
        while (cur.any()) {
            if (cur.test(s)) { cout << len << endl; found = true; break; }
            vis |= cur;

            bitset<MAXN> nxt;
            for (size_t j = cur._Find_first(); j < (size_t)n; j = cur._Find_next(j))
                nxt |= adj[j];

            cur = nxt & ~vis;
            ++len;
        }
        if (!found) cout << "NO WAY" << endl;
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
