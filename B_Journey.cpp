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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int cycle_sum = a + b + c;
        int cycle_count = n / cycle_sum;
        int remainder = n % cycle_sum;

        int ans = cycle_count * 3;

        if (remainder > 0)
        {
            if (remainder <= a)
            {
                ans += 1;
            }
            else if (remainder <= a + b)
            {
                ans += 2;
            }
            else
            {
                ans += 3;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
