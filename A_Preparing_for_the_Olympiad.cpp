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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > b[i + 1])
                ans += (a[i] - b[i+1]);
            // else ans+=a[i];
        }
        ans += a[n - 1];
        cout << ans << endl;
    }
    return 0;
}