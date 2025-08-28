#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n+1);
        vector<int> pre(n+1);
        for (int i = 1; i <= n; i++){
            cin >> v[i];
            pre[i]=pre[i-1]+v[i];
        }
        map<int, int> mp;
        int ans = 0, mx = 0;
        for (int i = n; i > 0; i--)
        {
            mp[pre[i]]++;
            mx = max(mx, mp[pre[i]]);
            if (v[i] == 0)
            {
                ans += mx;
                mx = 0;
                mp.clear();
            }
        }
        ans += mp[0];
        cout << ans << endl;
    }

    return 0;
}
