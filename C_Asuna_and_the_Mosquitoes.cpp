#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;

// Common Macros
#define vi vector<int>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define INF LLONG_MAX
#define MOD_INV(x) mod_exp(x, MOD - 2, MOD)
#define MAX 100000

// Debugging Helpers
template <typename T>
void dbg_vec(const T &v)
{
    cerr << "[ ";
    for (const auto &x : v)
        cerr << x << " ";
    cerr << "]" << endl;
}
// Fast Input/Output Functions
template <typename T>
void read(T &x) { cin >> x; }
template <typename T, typename... Args>
void read(T &first, Args &...rest)
{
    cin >> first;
    read(rest...);
}
template <typename T>
void read(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}
template <typename T>
void print(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

// Created by Deep
// Date : 07-04-2025
// Time : 10:55

// Solution Function
void solve()
{
    int n;
    read(n);
    vector<int> odd, even;
    int maxi = -1;
    FOR(i, 0, n)
    {
        int x;
        read(x);
        if (x & 1)
            odd.pb(x);
        else
            even.pb(x);
        maxi = max(maxi, x);
    }
    sort(all(odd), greater<int>());
    sort(all(even), greater<int>());
    if(maxi & 1) odd.erase(odd.begin(), odd.begin() + 1);
    else even.erase(even.begin(), even.begin() + 1);
    if ((maxi & 1 && even.size() == 0) || (maxi % 2 == 0 && odd.size() == 0))
    {
        cout << maxi << endl;
    }
    else
    {
        int evenSum = accumulate(all(even), 0LL);
        int oddSum = accumulate(all(odd), 0LL);
        if (maxi & 1)
        {
            maxi += evenSum;
            maxi += oddSum - (odd.size());
        }
        else
        {
            maxi += oddSum - (odd.size() - 1);
            maxi += evenSum;
        }
        cout << maxi << endl;
    }
}

// Main Function
int32_t main()
{
    fastio();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}