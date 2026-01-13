#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;

// Returns a bitmask (0-7) representing possible remainders {0, 1, 2}
int dfs(int u, int p) {
    bool is_leaf = true;
    int current_mask = 1; // Binary 001 -> Represents {0} (identity sum)

    for (int v : adj[u]) {
        if (v == p) continue;
        is_leaf = false;
        
        int child_mask = dfs(v, u);
        int next_mask = 0;

        // Combine current sums with child's sums
        // Iterate bits 0, 1, 2 for both current and child
        for (int i = 0; i < 3; i++) {
            if ((current_mask >> i) & 1) {       // If we have remainder i
                for (int j = 0; j < 3; j++) {
                    if ((child_mask >> j) & 1) { // And child has remainder j
                        next_mask |= (1 << ((i + j) % 3));
                    }
                }
            }
        }
        current_mask = next_mask;
    }

    if (is_leaf) {
        return 2; // Binary 010 -> Leaf MUST be shaken (count=1)
    } else {
        return current_mask | 2; // Either use children sums OR shake current (count=1)
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check if bit 0 (value 1) is set in the root's result
    if (dfs(1, -1) & 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}