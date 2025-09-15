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
    int n, m;
    cin >> n >> m;

    priority_queue<int> aMax, bMax;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        aMax.push(x);
        sumA += x;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        bMax.push(x);
        sumB += x;
    }

    if (sumA != sumB)
    {
        cout << "No" << endl;
        return;
    }

    while (!bMax.empty())
    {
        if (aMax.empty())
        {
            cout << "No" << endl;
            return;
        }

        int xb = bMax.top();
        int xa = aMax.top();

        if (xb == xa)
        {
            bMax.pop();
            aMax.pop();
            continue;
        }

        if (xb < xa)
        {
            cout << "No" << endl;
            return;
        }

        bMax.pop();
        int f = xb / 2;
        int s = (xb + 1) / 2;
        bMax.push(f);
        bMax.push(s);
    }

    if (aMax.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
