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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.rbegin(), v.rend());

        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {

            ans += v[i];
            if (ans == k)
                break;
            else if (ans > k)
            {
                ans = ans - v[i];
                break;
            }
        }
        if (ans == k)
            ans = 0;
        else
            ans = k - ans;
        cout << ans << endl;
    }
    return 0;
}