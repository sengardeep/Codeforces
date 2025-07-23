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
// Date : 08-04-2025
// Time : 21:12

// Solution Function
bool isPossible(const vector<int>& a, int k, int x) {
    unordered_set<int> st1;
    int count = 0;
    for (int num : a) {
        if (num < x) {
            st1.insert(num);
        }
        if ((int)st1.size() == x) {
            count++;
            st1.clear();
        }
    }
    return count >= k;
}
void solve()
{
    int n, k;
    read(n, k);

    vi v(n);
    unordered_map<int, int> freq;
    FOR(i, 0, n)
    {
        read(v[i]);
        freq[v[i]]++;
    }

    int total = 0;
    while (freq.count(total))
    {
        total++;
    }

    int start = 0, end = total, ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(v, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << ans << endl;
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