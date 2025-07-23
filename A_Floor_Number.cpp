#include <bits/stdc++.h>
#define MOD (const int)1e9 + 7
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
        int n, x;
        cin >> n >> x;
        int ans = 1;
        n -= 2;
        if (n > 0)
        {
            ans += n / x;
            n %= x;
        }
        if (n > 0)
            ans += 1;
        cout << ans << endl;
    }
    return 0;
}