#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

static inline bool goodSegment(const vector<int>& pref, int L, int R) {
    // c[i] = +/-1 is implied by pref; sum = pref[R+1] - pref[L]
    int len = R - L + 1;
    int sum = pref[R+1] - pref[L];
    return sum >= (len & 1);
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Build c[i] = +1 if a[i] <= k else -1, and prefix sums p (0-based, p[0]=0)
    vector<int> p(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int c = (a[i] <= k ? 1 : -1);
        p[i+1] = p[i] + c;
    }

    // Case 1: prefix + suffix
    // goodPrefix[l] = good([0..l]) for l in [0..n-3]
    vector<char> goodPrefix(n, 0);
    for (int l = 0; l <= n-3; ++l) {
        int len = l + 1;
        int sum = p[l+1] - p[0];
        if (sum >= (len & 1)) goodPrefix[l] = 1;
    }
    // goodSuffixStart[s] = good([s..n-1]) for s in [2..n-1]
    vector<char> goodSuffixStart(n, 0);
    for (int s = 2; s <= n-1; ++s) {
        int len = n - s;
        int sum = p[n] - p[s];
        if (sum >= (len & 1)) goodSuffixStart[s] = 1;
    }
    // prefixAnyUpTo[i] = exists l in [0..i] with goodPrefix[l]==true
    vector<char> prefixAnyUpTo(n, 0);
    for (int i = 0; i < n; ++i) {
        prefixAnyUpTo[i] = (i ? prefixAnyUpTo[i-1] : 0) || (i <= n-3 ? goodPrefix[i] : 0);
    }
    bool ok = false;
    for (int s = 2; s <= n-1 && !ok; ++s) {
        if (goodSuffixStart[s]) {
            int iMax = s - 2;
            if (iMax >= 0 && prefixAnyUpTo[iMax]) ok = true;
        }
    }
    if (ok) {
        cout << "YES\n";
        return;
    }

    // Case 2: prefix + middle
    // Maintain min p[i] by parity for i in [1..r] where prefix [0..i-1] is good.
    const int INF = 1e9;
    int minPWithGoodPrefix[2] = {INF, INF};
    int nextI = 1; // i = l+1
    for (int r = 1; r <= n-2 && !ok; ++r) {
        // Add all i <= r
        while (nextI <= r) {
            int l = nextI - 1;
            // good([0..l])?
            int len = l + 1;
            int sum = p[l+1] - p[0];
            if (sum >= (len & 1)) {
                int par = (nextI & 1);
                minPWithGoodPrefix[par] = min(minPWithGoodPrefix[par], p[nextI]);
            }
            ++nextI;
        }
        int pr = p[r+1];
        int sr = (r+1) & 1;
        int op = sr ^ 1;
        // Need p[nextI] <= pr - ((r+1 - nextI) % 2)
        bool midOK = (minPWithGoodPrefix[sr] <= pr) || (minPWithGoodPrefix[op] <= pr - 1);
        if (midOK) ok = true;
    }
    if (ok) {
        cout << "YES\n";
        return;
    }

    // Case 3: middle + suffix
    // Maintain min p[i] by parity for i in [1..r] (no prefix-good requirement)
    int minPAll[2] = {INF, INF};
    int nextI2 = 1;
    for (int r = 1; r <= n-2 && !ok; ++r) {
        while (nextI2 <= r) {
            int par = (nextI2 & 1);
            minPAll[par] = min(minPAll[par], p[nextI2]);
            ++nextI2;
        }
        int pr = p[r+1];
        int sr = (r+1) & 1;
        int op = sr ^ 1;
        bool midAny = (minPAll[sr] <= pr) || (minPAll[op] <= pr - 1);
        if (midAny && goodSuffixStart[r+1]) ok = true;
    }

    cout << (ok ? "YES\n" : "NO\n");
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
