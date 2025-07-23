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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int ans = 0;
        int seats1 = m, seats2 = m;
        if (a <= m)
        {
            ans += a;
            seats1 -= a;
        }
        else
        {
            ans += m;
            seats1 = 0;
        }
        if (b <= m)
        {
            ans += b;
            seats2 -= b;
        }
        else
        {
            seats2 = 0;
            ans += m;
        }

        int total = seats1 + seats2;
        if (total >= c)
            ans += c;
        else
            ans += total;
        cout << ans << endl;
    }
    return 0;
}