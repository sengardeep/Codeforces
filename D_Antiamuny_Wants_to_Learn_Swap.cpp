#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

struct SegTree
{
    int n;
    int INF;
    vector<int> seg;

    void init(int n_, int INF_)
    {
        n = n_;
        INF = INF_;
        seg.assign(4 * n + 5, INF);
    }

    void update(int idx, int val, int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = min(seg[node], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(idx, val, node << 1, l, mid);
        else
            update(idx, val, node << 1 | 1, mid + 1, r);
        seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
    }

    void update(int idx, int val) { update(idx, val, 1, 1, n); }

    int query(int ql, int qr, int node, int l, int r)
    {
        if (qr < l || r < ql)
            return INF;
        if (ql <= l && r <= qr)
            return seg[node];
        int mid = (l + r) >> 1;
        return min(query(ql, qr, node << 1, l, mid),
                   query(ql, qr, node << 1 | 1, mid + 1, r));
    }

    int query(int l, int r) { return query(l, r, 1, 1, n); }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> L(n + 1, 0), R(n + 1, n + 1);

    {
        vector<int> st;
        st.reserve(n);
        for (int i = 1; i <= n; ++i)
        {
            while (!st.empty() && a[st.back()] < a[i])
                st.pop_back();
            L[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }
    }

    {
        vector<int> st;
        st.reserve(n);
        for (int i = n; i >= 1; --i)
        {
            while (!st.empty() && a[st.back()] > a[i])
                st.pop_back();
            R[i] = st.empty() ? (n + 1) : st.back();
            st.push_back(i);
        }
    }

    struct Query
    {
        int r, idx;
    };
    vector<vector<Query>> byL(n + 2);
    vector<int> ql(q), qr(q);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        ql[i] = l;
        qr[i] = r;
        byL[l].push_back({r, i});
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i, int j)
         { return L[i] > L[j]; });

    const int INF = n + 5;
    SegTree st;
    st.init(n, INF);

    vector<char> ans(q, 1);

    int ptr = 0;
    for (int l = n; l >= 1; --l)
    {
        while (ptr < n && L[ord[ptr]] >= l)
        {
            int i = ord[ptr];
            st.update(i, R[i]);
            ++ptr;
        }
        for (auto &qq : byL[l])
        {
            int r = qq.r;
            int idx = qq.idx;
            if (r - l + 1 < 3)
            {
                ans[idx] = 1;
            }
            else
            {
                int minR = st.query(l, r);
                ans[idx] = (minR > r) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << (ans[i] ? "YES" : "NO") << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
