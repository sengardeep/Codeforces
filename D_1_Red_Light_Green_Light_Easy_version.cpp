#include <bits/stdc++.h>
using namespace std;
#define int long long

struct State {
    int index, dir, rem;
    int to_id(int k) const {
        return (index * 2 + (dir == 1 ? 0 : 1)) * k + rem;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n), d(n);
        map<int, int> pos_to_idx;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos_to_idx[p[i]] = i;
        }
        for (int i = 0; i < n; ++i) cin >> d[i];

        // Graph setup
        const int dir_val[2] = {1, -1}; // 0: right, 1: left
        int total_states = n * 2 * k;
        vector<int> out_dest(total_states, -2); // -1: escape, -2: unprocessed, >=0: state id
        vector<vector<int>> reverse_graph(total_states);

        for (int i = 0; i < n; ++i) {
            for (int dir : {-1, 1}) {
                for (int rem = 0; rem < k; ++rem) {
                    State cur = {i, dir, rem};
                    int idx = cur.to_id(k);

                    int new_dir = dir;
                    if (rem == d[i]) new_dir *= -1;

                    int ni = i + (new_dir == 1 ? 1 : -1);
                    if (ni < 0 || ni >= n) {
                        out_dest[idx] = -1; // escape state
                        continue;
                    }

                    int delta = abs(p[ni] - p[i]);
                    int new_rem = (rem + delta) % k;

                    State next = {ni, new_dir, new_rem};
                    int next_id = next.to_id(k);

                    out_dest[idx] = next_id;
                    reverse_graph[next_id].push_back(idx);
                }
            }
        }

        // BFS from exit states
        vector<bool> good(total_states, false);
        queue<int> q;
        for (int i = 0; i < total_states; ++i) {
            if (out_dest[i] == -1) {
                good[i] = true;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : reverse_graph[u]) {
                if (!good[v]) {
                    good[v] = true;
                    q.push(v);
                }
            }
        }

        // Query Processing
        int qn; cin >> qn;
        while (qn--) {
            int a; cin >> a;

            auto it = pos_to_idx.lower_bound(a);
            int i;
            if (it != pos_to_idx.end() && it->first == a) {
                i = it->second;
                State s = {i, 1, 0};
                cout << (good[s.to_id(k)] ? "YES\n" : "NO\n");
            } else {
                // Not on a light, move to the next one
                int dir, next_pos;
                if (it == pos_to_idx.end()) {
                    cout << "YES\n"; // Will walk off the end
                } else if (it == pos_to_idx.begin()) {
                    cout << "YES\n"; // Will walk off to left
                } else {
                    // Between two lights
                    int left_idx = prev(it)->second;
                    int right_idx = it->second;
                    int delta = p[right_idx] - a;
                    int rem = delta % k;
                    State s = {right_idx, -1, rem}; // walking into right light from left
                    cout << (good[s.to_id(k)] ? "YES\n" : "NO\n");
                }
            }
        }
    }
    return 0;
}
