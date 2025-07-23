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
        vector<int> v(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        int size = 0;
        int size2 = 0;
        for (auto it : mp)
            if (it.second > 1)
            {
                size += it.second;
                size2++;
            }

        cout << (((n - size + 1) / 2) * 2) + (size2 + 1 / 2) << endl;
    }
    return 0;
}