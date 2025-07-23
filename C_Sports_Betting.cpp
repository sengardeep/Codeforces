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

// Modular Arithmetic
class ModInt
{
public:
    int val;
    ModInt(int v = 0) : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    ModInt operator+(const ModInt &other) const { return ModInt(val + other.val); }
    ModInt operator-(const ModInt &other) const { return ModInt(val - other.val); }
    ModInt operator*(const ModInt &other) const { return ModInt(val * other.val); }
    ModInt pow(int exp) const
    {
        ModInt base = *this, res = 1;
        while (exp)
        {
            if (exp % 2)
                res = res * base;
            base = base * base;
            exp /= 2;
        }
        return res;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt operator/(const ModInt &other) const { return *this * other.inv(); }
};

// Utility Functions
int gcd(int v, int b) { return b ? gcd(b, v % b) : v; }
int lcm(int v, int b) { return (v / gcd(v, b)) * b; }
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
// Date : 26-04-2025
// Time : 15:22

// Solution Function
void solve()
{
    int n;
    read(n);
    vi v(n);
    map<int, int> mp;
    FOR(i, 0, n)
    {
        read(v[i]);
        mp[v[i]]++;
    }
    bool flag = false;
    vi temp;
    for (auto it : mp)
    {
        temp.pb(it.first);
        if (it.second >= 4)
            flag = true;
    }
    if (flag)
    {
        YES return;
    }
    sort(all(temp));
    int count = 0, prev = INT_MIN;
    for (auto k : temp)
    {
        if (k != prev + 1)
            count = 0;
        if (mp[k] >= 2)
        {
            count++;
            if (count >= 2)
            {
                flag = true;
                break;
            }
        }
        prev = k;
    }
    if (flag) YES 
    else NO
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