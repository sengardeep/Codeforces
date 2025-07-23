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
        int a, b, c;
        cin >> a >> b >> c;
        int maxi = max({a, b, c});
        if ((maxi != b && maxi != c) || (maxi != a && maxi != b) || (maxi != a && maxi != c))
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int x, y, z;
        if (a == b)
        {
            x = a;
            y = c;
            z = c;
        }
        else if (b == c)
        {
            z = b;
            x = a;
            y = a;
        }
        else
        {
            y = a;
            x = b;
            z = b;
        }

        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}