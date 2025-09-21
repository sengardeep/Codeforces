#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '1')
            continue;

        int start = i;
        int count = 0; // number of 01
        while (i + 2 < n && s[i + 1] == '0' && s[i + 2] == '1')
        {
            count++;
            i += 2; // go to 01
        }
        int end = i;

        if (count % 2 == 1)
        {
            bool left = (start - 1 >= 0 && s[start - 1] == '0');
            bool right = (end + 1 < n && s[end + 1] == '0');
            if (!left && !right)
            {
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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