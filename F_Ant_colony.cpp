#include <bits/stdc++.h>
using namespace std;
#define int long long

// ----------- Sparse Table for GCD -----------
struct SparseTable {
    int n, LOG;
    vector<vector<int>> st;
    vector<int> lg;

    SparseTable(const vector<int>& arr) {
        n = arr.size();
        LOG = 32 - __builtin_clz(n); // ceil(log2(n))
        st.assign(n, vector<int>(LOG));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        for (int i = 0; i < n; i++) st[i][0] = arr[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[i][k] = __gcd(st[i][k-1], st[i + (1 << (k-1))][k-1]);
            }
        }
    }

    int query(int l, int r) { // inclusive [l, r]
        int k = lg[r - l + 1];
        return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
// ----------- End of Sparse Table -----------


// ----------- Merge Sort Tree -----------
struct MergeSortTree {
    int n;
    vector<vector<int>> tree;

    MergeSortTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n-1, arr);
    }

    void build(int index, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[index] = {arr[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2*index, start, mid, arr);
        build(2*index+1, mid+1, end, arr);
        tree[index].resize(tree[2*index].size() + tree[2*index+1].size());
        merge(tree[2*index].begin(), tree[2*index].end(),
              tree[2*index+1].begin(), tree[2*index+1].end(),
              tree[index].begin());
    }

    int query(int index, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return 0;
        if (start >= l && end <= r) {
            auto lo = lower_bound(tree[index].begin(), tree[index].end(), val);
            auto hi = upper_bound(tree[index].begin(), tree[index].end(), val);
            return (end-start+1)-(hi - lo);
        }
        int mid = (start + end) / 2;
        return query(2*index, start, mid, l, r, val) +
               query(2*index+1, mid+1, end, l, r, val);
    }

    int query(int l, int r, int val) {
        return query(1, 0, n-1, l, r, val);
    }
};
// ----------- End of Merge Sort Tree -----------


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SparseTable st(v);
    MergeSortTree mst(v);

    int q; 
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--; // convert to 0-based
        int g = st.query(l, r);
        cout << mst.query(l, r, g) << "\n";
    }
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
