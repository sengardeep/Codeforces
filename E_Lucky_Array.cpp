#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Precompute all lucky numbers (digits only 4/7) up to a safe upper bound.
    // LIM must be >= any possible array value during the process (after all adds).
    // 1e12 is typically safe for Codeforces constraints; increase if needed.
    const long long LIM = (long long)1e12;
    vector<int> lucky;
    function<void(long long)> gen = [&](long long x) {
        if (x > LIM) return;
        if (x > 0) lucky.push_back(x);
        gen(x * 10 + 4);
        gen(x * 10 + 7);
    };
    gen(0);
    sort(lucky.begin(), lucky.end());

    // Smallest lucky number >= x
    auto nextLucky = [&](long long x) -> long long {
        auto it = lower_bound(lucky.begin(), lucky.end(), x);
        if (it == lucky.end()) return lucky.back(); // assumes LIM is large enough
        return *it;
    };

    // Core idea:
    // For each position i, maintain
    //   to[i] = current target lucky number >= A[i]
    //   D[i]  = to[i] - A[i]   (distance to next lucky)
    // During "add l r x": A[i] += x, hence D[i] -= x.
    // If D[i] becomes <= 0, we have reached/passed to[i], so we must advance to[i]
    // to the next lucky >= A[i] and reset D[i] accordingly.
    vector<int> to(n);
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        to[i] = nextLucky(a[i]);
        D[i] = to[i] - a[i];
    }

    // Segment tree over D:
    // - stMin: minimum D in the node's range
    // - stCnt: number of positions having that minimum D in the range
    // - lazy:  pending add for D (range add)
    //
    // Why this works:
    // - Count query for [l, r]: if min D == 0, then exactly stCnt positions are lucky.
    //   Otherwise, no position has D == 0 (since min > 0), so answer is 0.
    // - Add query: apply -x to D on [l, r], then fix all leaves with D <= 0 by
    //   advancing to the next lucky and recomputing D.
    vector<int> stMin(4 * n, 0), stCnt(4 * n, 0), lazy(4 * n, 0);

    auto pull = [&](int p) {
        if (stMin[2 * p] < stMin[2 * p + 1]) {
            stMin[p] = stMin[2 * p];
            stCnt[p] = stCnt[2 * p];
        } else if (stMin[2 * p] > stMin[2 * p + 1]) {
            stMin[p] = stMin[2 * p + 1];
            stCnt[p] = stCnt[2 * p + 1];
        } else {
            stMin[p] = stMin[2 * p];
            stCnt[p] = stCnt[2 * p] + stCnt[2 * p + 1];
        }
    };
    function<void(int,int,int)> build = [&](int p, int l, int r) {
        if (l == r) {
            stMin[p] = D[l];
            stCnt[p] = 1; // exactly one element in a leaf
            return;
        }
        int m = (l + r) >> 1;
        build(2 * p, l, m);
        build(2 * p + 1, m + 1, r);
        pull(p);
    };
    auto apply = [&](int p, int val) {
        stMin[p] += val;
        lazy[p] += val;
    };
    auto push = [&](int p) {
        if (lazy[p] != 0) {
            apply(2 * p, lazy[p]);
            apply(2 * p + 1, lazy[p]);
            lazy[p] = 0;
        }
    };
    // Range add over D (not A): A += x => D -= x
    function<void(int,int,int,int,int,int)> rangeAdd = [&](int p, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(p, val);
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        rangeAdd(2 * p, l, m, ql, qr, val);
        rangeAdd(2 * p + 1, m + 1, r, ql, qr, val);
        pull(p);
    };
    // Query returns (minD, countOfMinD) in [ql, qr]
    function<pii(int,int,int,int,int)> query = [&](int p, int l, int r, int ql, int qr) -> pii {
        if (qr < l || r < ql) return { (int)LLONG_MAX, 0 };
        if (ql <= l && r <= qr) return { stMin[p], stCnt[p] };
        push(p);
        int m = (l + r) >> 1;
        auto L = query(2 * p, l, m, ql, qr);
        auto R = query(2 * p + 1, m + 1, r, ql, qr);
        if (L.first < R.first) return L;
        if (L.first > R.first) return R;
        return { L.first, L.second + R.second };
    };

    // Fix all positions with D <= 0 in [ql, qr]:
    // We descend only into nodes with stMin <= 0 (others can't contain invalid leaves).
    // For a leaf:
    //   Let Dj = D[i] (with all lazy applied), Ai = to[i] - Dj (current A[i]).
    //   We must set to[i] = nextLucky(Ai) and D[i] = to[i] - Ai (> 0).
    function<void(int,int,int,int,int)> fixNonPos = [&](int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql || stMin[p] > 0) return; // prune if no invalid D in this node
        if (l == r) {
            long long Dj = stMin[p];      // <= 0
            long long Ai = to[l] - Dj;    // recover current A[i]
            long long nxt = nextLucky(Ai);
            to[l] = nxt;
            stMin[p] = nxt - Ai;          // new D[i] > 0
            stCnt[p] = 1;
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        if (ql <= m) fixNonPos(2 * p, l, m, ql, qr);
        if (m < qr)  fixNonPos(2 * p + 1, m + 1, r, ql, qr);
        pull(p);
    };

    build(1, 0, n - 1);

    while (q--) {
        string s; cin >> s;
        if (s == "count") {
            int l, r; cin >> l >> r; --l; --r;
            auto res = query(1, 0, n - 1, l, r);
            // If the minimum D in [l, r] is 0, exactly res.second elements are lucky.
            if (res.first == 0) cout << res.second << endl;
            else cout << 0 << endl;
        } else { // "add l r x": increase A by x => decrease D by x
            int l, r, x; cin >> l >> r >> x; --l; --r;
            rangeAdd(1, 0, n - 1, l, r, -x);
            // Some D may have become <= 0; advance them to the next lucky and fix D.
            fixNonPos(1, 0, n - 1, l, r);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
