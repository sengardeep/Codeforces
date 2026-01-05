#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, m;
    cin >> n >> r >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> owner(n + 1, -1);
    vector<int> dist(n + 1, -1);
    vector<int> strength(m);

    queue<int> q;

    for (int i = 0; i < m; i++) {
        int k, s;
        cin >> k >> s;
        strength[i] = s;

        if (owner[k] != -1) {
            cout << "No\n";
            return;
        }

        owner[k] = i;
        dist[k] = 0;
        q.push(k);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int id = owner[u];

        if (dist[u] == strength[id]) continue;

        for (int v : adj[u]) {
            if (owner[v] == -1) {
                owner[v] = id;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if (owner[v] != id) {
                cout << "No\n";
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (owner[i] == -1) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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
