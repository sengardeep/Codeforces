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
// Date : 13-04-2025
// Time : 21:37

// Solution Function
void solve()
{
    string s, t;
    read(s, t);
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
    for (auto it : s)
    {
        l1 += it == 'L';
        r1 += it == 'R';
    }
    for (auto it : t)
    {
        l2 += it == 'L';
        r2 += it == 'R';
    }
    if (l1 > l2 || r1 > r2)
    {
        NO return;
    }
    int k1 = 0, k2 = 0;
    FOR(i, 0, s.size())
    {
        int l = i, r = i;
        char c = s[l];
        while (s[r] == c && r < s.size())
            r++;
        r--;
        i = r;
        int segLength1 = r - l + 1;
        if (s[l] != t[k1])
        {
            NO return;
        }
        c = t[k1];
        while (t[k2] == c && k2 < t.size())
            k2++;
        int segLength2 = k2 - k1;
        k1 = k2;
        if (segLength1 > segLength2 || segLength2 > 2 * segLength1)
        {
            NO return;
        }
    }
    if(k2 < t.size()) NO
    else
    YES
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