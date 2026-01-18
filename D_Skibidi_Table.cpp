#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            int x, y;
            cin >> x >> y;
            int ans = 0;
            for (int k = n - 1; k >= 0; k--)
            {
                int half = 1LL << k;   
                int area = half * half; 
                if (x <= half && y <= half)
                {}
                else if (x > half && y > half)
                {
                    ans += area;
                    x -= half;
                    y -= half;
                }
                else if (x > half && y <= half)
                {
                    ans += 2 * area;
                    x -= half;
                }
                else
                {
                    ans += 3 * area;
                    y -= half;
                }
            }
            cout << ans + 1 << endl;
        }
        else
        {
            int d;
            cin >> d;
            int i = 1, j = 1;
            int x = ((1LL << n) *1LL* (1LL << n)) / 4;
            int y = 1 << (n - 1);
            while (x > 0)
            {
                int div = (d + x - 1) / x;
                if (div == 1)
                {
                }
                else if (div == 2)
                {
                    i += (y);
                    j += (y);
                }
                else if (div == 3)
                {
                    i += (y);
                }
                else
                {
                    j += (y);
                }
                d -= (x * 1LL *(div - 1));
                x /= 4;
                y /= 2;
            }
            cout << i << " " << j << endl;
        }
    }
}

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
        solve();
    }

    return 0;
}
