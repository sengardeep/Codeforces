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
        int n;
        cin >> n;
        vector<int> arr(n);
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                odd++;
            else
                even++;
        }
        if (odd == 0 || (odd == n && !(n & 1) ))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}