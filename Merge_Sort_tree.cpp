#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<multiset<int>> tree(4 * n);

    // Build function
    function<void(int,int,int)> build = [&](int start, int end, int index) {
        if (start == end) {
            tree[index].insert(v[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].insert(tree[2 * index].begin(), tree[2 * index].end());
        tree[index].insert(tree[2 * index + 1].begin(), tree[2 * index + 1].end());
    };

    // Query: smallest number >= val in range [l,r]
    function<int(int,int,int,int,int,int)> query = [&](int start, int end, int index, int l, int r, int val) -> int {
        if (r < start || l > end) return INF;
        if (start >= l && end <= r) {
            auto it = tree[index].lower_bound(val);
            if (it != tree[index].end()) return *it;
            return INF;
        }
        int mid = (start + end) / 2;
        return min(
            query(start, mid, 2 * index, l, r, val),
            query(mid + 1, end, 2 * index + 1, l, r, val)
        );
    };

    // Update: v[pos] = new_val
    function<void(int,int,int,int,int)> update = [&](int start, int end, int index, int pos, int new_val) {
        // erase old value
        tree[index].erase(tree[index].find(v[pos]));
        // insert new value
        tree[index].insert(new_val);

        if (start == end) return;

        int mid = (start + end) / 2;
        if (pos <= mid) update(start, mid, 2 * index, pos, new_val);
        else update(mid + 1, end, 2 * index + 1, pos, new_val);
    };

    // Build the tree
    build(0, n - 1, 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Query
            int l, r, x;
            cin >> l >> r >> x;
            int ans = query(0, n - 1, 1, l, r, x);
            if (ans == INF) cout << -1 << "\n";
            else cout << ans << "\n";
        } else {
            // Update
            int i, x;
            cin >> i >> x;
            update(0, n - 1, 1, i, x);
            v[i] = x;
        }
    }

    return 0;
}
