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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    map<int, int> map;
    for (auto it : v) map[it]++;
    int sum = 0, k = 0;
    vector<int> rem;
    for (auto [num, f] : map) {
        if (f % 2) {
            sum += num * (f - 1);
            rem.push_back(num);
            k += (f - 1);
        } else {
            sum += num * f;
            k += f;
        }
    }
    multiset<int> ms;
    for (int it : rem) ms.insert(it);
    int extra = 0;
    while (extra < 2 && !ms.empty())
    {
        auto it = ms.lower_bound(sum);
        if (it == ms.begin()) break; 
        --it;
        sum += *it;
        ms.erase(it);
        extra++;
    }
    if (k + extra >= 3) cout << sum << endl;
    else cout << 0 << endl;
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
