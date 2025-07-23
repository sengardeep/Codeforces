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
        vector<int> arr1(n);
        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];

        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max({arr1[i], arr2[i]});
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, sum + min({arr1[i], arr2[i]}));
        }

        cout << ans << endl;
    }
    return 0;
}