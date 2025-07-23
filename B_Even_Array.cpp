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
        int n;
        cin >> n;
        int even = 0, odd = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] & 1)
                odd++;
            else
                even++;
        }

        if ((n & 1 && even - 1 != odd) || ((!(n & 1)) && even != odd))
        {
            cout << "-1" << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 != v[i] % 2)
                ans++;
        }

        cout << ans / 2 << endl;
    }
    return 0;
}