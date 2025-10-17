#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(auto& d : dir){
            int nr = curr.first + d.first;
            int nc = curr.second + d.second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[curr.first][curr.second] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool flag1 = (i >= s && i < n - s && j >= s && j < m - s);
            bool flag2 = (dist[i][j] == -1 || dist[i][j] > s);
            
            if (flag1 && flag2) {
                v[i][j] = '*';
            }
        }
    }
    int ans = 0, count = 0;
    auto check2 = [&](int r, int c) {
        if (r < 0 || r > n - 1 || c < 0 || c > m - 1) return false;
        return true;
    };
    function<void(int, int)> dfs = [&](int r, int c) -> void {
        count++;
        v[r][c] = '.';
        for (int i = 0; i < 4; i++) {
            int ro = r + dir[i].first, co = c + dir[i].second;
            if (check2(ro, co) == false) continue;
            if (v[ro][co] == '*') dfs(ro, co);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*') {
                count = 0;
                dfs(i, j);
                ans = max(ans, count);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}