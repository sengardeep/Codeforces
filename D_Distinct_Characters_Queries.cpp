#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> segTree(4 * n);
    auto merge = [](int a, int b)
    {
        return a | b;
    };
    function<void(int, int, int)> build = [&](int start, int end, int index) -> void
    {
        if (start == end)
        {
            segTree[index] = (1 << (s[start] - 'a'));
            return;
        }

        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
    };

    function<void(int, int, int, int, char)> update = [&](int start, int end, int index, int pos, char c) -> void
    {
        if (start == end)
        {
            segTree[index] = (1 << (c - 'a'));
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid)
            update(start, mid, 2 * index, pos, c);
        else
            update(mid + 1, end, 2 * index + 1, pos, c);
        segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
    };

    function<int(int, int, int, int, int)> query = [&](int start, int end, int index, int l, int r) -> int
    {
        if (end < l || start > r)
            return 0; // no overlap
        if (start >= l && end <= r)
            return segTree[index]; // Total overlap
        int mid = (start + end) / 2;
        int left = query(start, mid, 2 * index, l, r);
        int right = query(mid + 1, end, 2 * index + 1, l, r);
        return merge(left, right);
    };
    build(0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >> i;
            char c;
            cin >> c;
            --i;
            update(0, n - 1, 1, i, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(query(0, n - 1, 1, l - 1, r - 1)) << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
