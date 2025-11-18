#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> v(m);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        v[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> v[i][j];
            if (v[i][j] >= 1 && v[i][j] <= n) {
                adj[v[i][j]].push_back(i);
            }
        }
    }

    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int x : adj[top]) {
            const auto& tmp = v[x];
            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == top) {
                    for (int i = 1; i <= k && j + i < tmp.size(); i++) {
                        int cnt = tmp[j + i];
                        if (cnt >= 1 && cnt <= n && dist[cnt] == -1) {
                            dist[cnt] = dist[top] + 1;
                            q.push(cnt);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1) ans += dist[i] * i;
        else ans += -1 * i;
    }
    cout << ans << endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int t=1;
   cin>>t;
   int i=1;
   while(t--){
      cout<<"Case #"<<i++<<": ";
      solve();
   }
   return 0;
}