#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Observation 1: gcd(l..r) is non-increasing when r increases.
    // i.e., as we extend the subarray, gcd can only stay same or decrease.

    // Observation 2: The gcd sequence for fixed l has at most O(log(max(ai))) distinct values.
    // Reason: whenever gcd decreases, it must at least halve.

    // Observation 3: gcd(l..r) is piecewise constant.
    // That means it stays flat for an interval [r..r’] before dropping to a smaller value.
    // So we can count whole intervals of subarrays at once, not one by one.

    // Observation 4: Sparse Table (or Segment Tree) lets us compute gcd(l..r) quickly.
    // Then we can binary search the farthest r’ where gcd stays the same.
    // This avoids O(n^2) subarray checks.

    int n;
    cin >> n;
    vector<int> v(n);
    auto f = [](int n)
    {
        int ans = 0;
        while (1 << (ans + 1) <= n)
            ans++;
        return ans;
    };
    int LOG = f(n);
    vector<vector<int>> st(n, vector<int>(LOG + 1));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st[i][0] = v[i];
    }

    // Preprocessing
    for (int j = 1; j <= LOG; j++)
        for (int i = 0; i + (1 << (j)) - 1 < n; i++)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    function<int(int, int)> query = [&](int l, int r) -> int
    {
        int len = r - l + 1;
        int k = f(len);
        return gcd(st[l][k], st[r - (1 << k) + 1][k]);
    };

    map<int, int> ans; // number of subarrays having gcd i

    for (int i = 0; i < n; i++)
    {
        int r = i;
        int g = v[i];
        while (r < n)
        {
            g = gcd(g, v[r]); // progressively extend gcd
            int low = r, high = n - 1, last = r;
            // find the farthest position where gcd(i..mid) == g
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (query(i, mid) == g)
                {
                    last = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            ans[g] += (last - r + 1); // add count of subarrays for this gcd
            r = last + 1;             // jump directly, don't go step by step
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
