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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    map<int, int> map1, map2;
    int flag = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == b[i])
        {
            cout << (i + 1) << endl;
            return;
        }
        else
        {
            if (flag)
            {
                if (map2.count(a[i]) || map1.count(b[i]))
                {
                    cout << (i + 1) << endl;
                    return;
                }
                if (map2.count(b[i]))
                {
                    if (a[i + 1] != b[i])
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                    else if (map2[b[i]] > 1)
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                }
                if (map1.count(a[i]))
                {
                    if (b[i + 1] != a[i])
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                    else if (map1[a[i]] > 1)
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                }
            }
            else
            {
                if (map1.count(a[i]) || map2.count(b[i]))
                {
                    cout << (i + 1) << endl;
                    return;
                }
                if (map1.count(b[i]))
                {
                    if (a[i + 1] != b[i])
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                    else if (map1[b[i]] > 1)
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                }
                if (map2.count(a[i]))
                {
                    if (b[i + 1] != a[i])
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                    else if (map2[a[i]] > 1)
                    {
                        cout << (i + 1) << endl;
                        return;
                    }
                }
            }
        }
        if (flag)
        {
            map1[a[i]]++;
            map2[b[i]]++;
        }
        else
        {
            map2[a[i]]++;
            map1[b[i]]++;
        }
        flag ^= 1;
    }
    cout << 0 << endl;
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
