#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define dbg(it) cerr << #it << " = " << (it) << endl
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define INF LLONG_MAX
#define MOD_INV(it) mod_exp(it, MOD - 2, MOD)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template <typename t>
void dbg_vec(const t &v)
{
    cerr << "[ ";
    for (const auto it : v)
        cerr << it << " ";
    cerr << "]" << endl;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int mod_exp(int base, int exp, int mod = MOD)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Fast Input/Output Functions
template <typename t>
void read(t &it) { cin >> it; }

template <typename t, typename... Args>
void read(t &first, Args &...rest)
{
    cin >> first;
    read(rest...);
}

template <typename t>
void read(vector<t> &v)
{
    for (auto &it : v) 
        cin >> it;
}

template <typename t>
void print(const vector<t> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

// Created by Deep
// Date : 10-08-2025
// Time : 20:20


int rep(int x, int k)
{
    int r = ((x % k) + k) % k;
    int r2 = (k - r) % k;
    return min(r, r2);
}

// Solution Function
void solve()
{
    int n, k;
    read(n, k);
    vi s(n), t(n);
    read(s);
    read(t);
    

    map<int, int> freq;

    for (auto it : s)
    {
        freq[rep(it, k)]++;
    }
    for (auto it : t)
    {
        freq[rep(it, k)]--;
    }

    for (auto &it : freq)
    {
        if (it.second != 0)
        {
            NO
            return;
        }
    }
    YES
}

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
