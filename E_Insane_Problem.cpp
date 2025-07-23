#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        int K = 1, ans = 0;
        while (K <= r2 / l1)
        {
            int d = min(r1, r2 / K) - max(l1, l2 / K + !!(l2 % K));
            if (d >= 0)
                ans += d + 1;
            K *= k;
        }
        cout << ans << "\n";
    }
    return 0;
}