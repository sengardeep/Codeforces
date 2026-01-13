#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = -1;
    int start = 0, end = 30;
    auto check = [&](int x)
    {
        int d = 1LL << x;
        return n / d;
    };
    while (start <= end)
    {
        int mid = end + (start - end) / 2;
        if (check(mid) <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    if (ans == -1)
    {
        cout << -1 << endl;
        return;
    }
    int d = 1LL << ans;
    int a = n / d; 
    int r = n % d; 
    if (a == k || (a + 1 == k && r > 0))
        cout << ans << endl;
    else
        cout << -1 << endl;
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
