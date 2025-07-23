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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, z;

        x = (a + b) >> 1;
        y = (b + c) >> 1;
        z = -1;

        int low = c, high = d;
        while (low <= high)
        {
            int mid = high + ((low - high) >> 1);

            if ((x + y) > mid)
            {
                z = mid;
                break;
            }
            else
                high = mid - 1;
        }

        if (z == -1)
        {
            z = c;
            low = b, high = c;
            while (low <= high)
            {
                int mid = high + ((low - high) >> 1);
                if ((x + mid) > c)
                {
                    y = mid;
                    break;
                }
                else
                    low = mid + 1;
            }
        }
        cout << x << " " << y << " " << z << " " << endl;
    }
    return 0;
}