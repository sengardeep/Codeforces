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
// Date : 28-04-2025
// Time : 20:55
const int MAX = 7e6 + 5;
vi prime;
vi pre;
void sieve()
{
    vector<bool> inPrime(MAX, true);
    inPrime[0] = inPrime[1] = false;
    for (int i = 2; i * i < MAX; i++)
    {
        if (inPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
                inPrime[j] = false;
        }
    }
    for (int i = 2; i < MAX; i++)
    {
        if (inPrime[i])
            prime.pb(i);
    }

    pre.pb(0);
    for (int i = 0; i < prime.size(); ++i)
    {
        pre.pb(pre.back() + prime[i]);
    }
}

// Solution Function
void solve()
{
    int n;
    read(n);
    vi v(n);
    read(v);

    sort(all(v));
    reverse(all(v));

    vi pre1(n + 1, 0);
    FOR(i,0,n)
    {
        pre1[i + 1] = pre1[i] + v[i];
    }

    int ans = 0;
    FOR(k,0,n+1)
    {
        if (pre1[k] >= pre[k])
        {
            ans = k;
        }
        else
        {
            break;
        }
    }

    cout << n - ans << endl;
}

// Main Function
int32_t main()
{
    fastio();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}