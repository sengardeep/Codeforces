#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define int long long
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int pre = 0, ans = 0;
        map<int, int> mp;
        mp[0] = 1;

        for (auto it : arr)
        {
            pre += it;

            if (mp[pre] != 0)
            {
                ans++;
                mp.clear();

                mp[0] = 1;
                pre = 0;
            }

            mp[pre]++;
        }

        cout << ans << endl;
    }
    return 0;
}