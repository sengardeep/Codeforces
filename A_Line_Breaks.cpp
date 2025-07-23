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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        vector<int> length(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            length[i] = s[i].size();
        }

        // sort(length.begin(), length.end());
        int ans = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            ans += length[i];
            res++;
            if (ans > m)
            {
                res -= 1;
                break;
            }
            if (ans == m)
                break;
        }

        cout << res << endl;
    }
    return 0;
}