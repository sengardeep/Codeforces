#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
void solve()
{
    int n;
    cin >> n;
    // int ans = 0;
    int x = 1;
    // if (n < 4)
    // {
    //     cout << 1 << endl;
    //     return;
    // }
    while (n > 3)
    {
        n /= 4;
        // ans += x;
        x *= 2;
    }

    cout << x << endl;
}
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}