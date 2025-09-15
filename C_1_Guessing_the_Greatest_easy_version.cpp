#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
// #define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
int ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int smax_pos = ask(1, n);
    int max_pos = -1;

    if (smax_pos > 1) {
        int p = ask(1, smax_pos);
        if (p == smax_pos) {
            int l = 1, r = smax_pos - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (ask(mid, smax_pos) == smax_pos) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            max_pos = l;
        }
    }

    if (max_pos == -1) {
        int l = smax_pos + 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ask(smax_pos, mid) == smax_pos) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        max_pos = l;
    }

    cout << "! " << max_pos << endl;
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
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
