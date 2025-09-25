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
    int m = 2 * n;
    vector<int> v(m + 1);
    for (int i = 1; i <= m; i++) cin >> v[i];
    vector<int> diff(m, 0);
    for (int i = 1; i <= m - 1; i++) diff[i] = v[i + 1] - v[i];
    vector<int> pre1(m, 0), pre2(m, 0), even(m, 0), odd(m, 0);
    for (int i = 1; i <= m - 1; i++)
    {
        pre1[i] = pre1[i - 1] + diff[i];
        pre2[i] = pre2[i - 1] + diff[i] * i;
        if(i&1)
        {
            odd[i] = odd[i - 1] +  diff[i];
            even[i] = even[i-1];
        }
        else
        {
            even[i] = even[i - 1] + diff[i];
            odd[i]=odd[i-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        // Left contribution i * diff[i]
        int left = pre2[i];
        int mid = 0;
        if (i < n)
        {
            int L = i + 1;
            int R = (m - 1) - i; 
            if (L <= R)
            {
                int temp = pre1[R] - pre1[L - 1];
                mid += (i - 1) * temp;
                if (i % 2 == 0)
                {
                    mid += (even[R] - even[L - 1]);
                }
                else
                {
                    mid += (odd[R] - odd[L - 1]);
                }
            }
        }
        // Right contribution (m - i) * diff[i]
        int Lr = m - i;
        int Rr = m - 1;
        int sum1 = pre1[Rr] - pre1[Lr - 1];
        int sum2 = pre2[Rr] - pre2[Lr - 1];
        int right = m * sum1 - sum2;
        ans = left + mid + right;
        if (i == n) ans -= n * diff[n];
        cout << ans << " ";
    }
    cout<<endl;
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
