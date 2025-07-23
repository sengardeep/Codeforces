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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m), b(k);
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < k; i++)
            cin >> b[i];
        string ans = "";
        if (k == n)
        {
            for (int i = 0; i < m; i++)
                ans += '1';
            cout << ans << endl;
            continue;
        }
        if (k == n - 1)
        {
            // int missing=0;
            sort(b.begin(), b.end());
            int num = 1;
            for (int i = 0; i < k; i++)
            {
                if (b[i] == num)
                    num++;
                else
                    break;
            }
            for (int i = 0; i < m; i++)
            {
                if (a[i] == num)
                    ans += '1';
                else
                    ans += '0';
            }

            cout << ans << endl;
            continue;
        }
        for (int i = 0; i < m; i++)
            ans += '0';
        cout << ans << endl;
    }
    return 0;
}