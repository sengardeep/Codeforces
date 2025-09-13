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
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto [x, f] : mp)
    {
        if (f % k)
        {
            cout << 0 << endl;
            return;
        }
    }

    // mp2[v] = mp[v] / k
    map<long long, long long> mp2;
    for (auto p : mp)
        mp2[p.first] = p.second / k;

    // counting subarrays with per-value freq <= mp2
    map<long long, long long> freq;
    long long start = 0, end = 0;
    long long ans = 0;
    while (end < n)
    {
        long long x = v[end];
        freq[x]++;

        while (freq[x] > mp2[x])
        {
            long long y = v[start++];
            freq[y]--;
        }

        ans += (end - start + 1);
        end++;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
