#include <iostream>
#include <vector>

// Define a maximum size for our arrays to be safe.
const int MAXN = 50001;

// parent[i] stores the parent of node i in the DSU tree.
int parent[MAXN];

// rel[i] stores the relationship between node i and its parent.
// 0: i is the same kind as parent[i].
// 1: parent[i] eats i.
// 2: i eats parent[i].
// This is equivalent to: rel[i] = (kind[i] - kind[parent[i]] + 3) % 3
int rel[MAXN];

// The find function finds the root of the set containing x.
// It also performs path compression and updates the relationship 'rel[x]'.
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    // Store the old parent before recursion
    int old_parent = parent[x];
    // Recursively find the root of the set
    parent[x] = find(old_parent);
    // Path Compression: Update rel[x] to be its relationship with the new parent (the root).
    // The new relation is the sum of the old relations along the path.
    rel[x] = (rel[x] + rel[old_parent]) % 3;
    return parent[x];
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    // Initialize the DSU for n animals.
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rel[i] = 0;
    }

    int false_statements = 0;

    for (int i = 0; i < k; ++i) {
        int d, x, y;
        std::cin >> d >> x >> y;

        // --- Condition 1: X or Y is larger than n ---
        if (x > n || y > n) {
            false_statements++;
            continue;
        }
        
        // --- Condition 2: X eats X ---
        // Note: d=1 means "same kind", d=2 means "x eats y"
        if (d == 2 && x == y) {
            false_statements++;
            continue;
        }

        // Find the roots of the sets for x and y.
        // This also updates rel[x] and rel[y] to be relative to their roots.
        int rootX = find(x);
        int rootY = find(y);

        // The relationship type required by the statement.
        // d=1 (same kind) means a required difference of 0.
        // d=2 (x eats y) means a required difference of 1 ( (kind[x]+1)%3 = kind[y] ).
        int required_rel = (d == 1) ? 0 : 1;

        if (rootX == rootY) {
            // --- They are already in the same set, check for contradictions ---
            // The existing relationship difference between y and x.
            int existing_rel = (rel[y] - rel[x] + 3) % 3;
            if (existing_rel != required_rel) {
                // The statement contradicts what we already know.
                false_statements++;
            }
        } else {
            // --- They are in different sets, merge them ---
            // This statement is considered true as it provides new information.
            // We merge rootY's set into rootX's set.
            parent[rootY] = rootX;
            // We calculate the relationship of rootY to its new parent, rootX.
            // This formula ensures the relationship between x and y is correctly established.
            rel[rootY] = (rel[x] - rel[y] + required_rel + 3) % 3;
        }
    }

    std::cout << false_statements << std::endl;
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}