#include <bits/stdc++.h>
#define int long long
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;
const int MOD = 998244353;

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
template <typename T> void dbg_vec(const T &v) {
    cerr << "[ ";
    for (const auto &x : v) cerr << x << " ";
    cerr << "]" << endl;
}

// Utility Functions
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}
int mod_exp(int base, int exp, int mod = MOD) {
    int result = 1;
    while (exp) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
// Fast Input/Output Functions
template<typename T> void read(T& x) { cin >> x; }
template<typename T, typename... Args>
void read(T& first, Args&... rest) {
    cin >> first;
    read(rest...);
}
template<typename T> void read(vector<T>& v) { for (auto &x : v) cin >> x; }
template<typename T> void print(const vector<T>& v) { for (auto &x : v) cout << x << " "; cout << endl; }


// Created by Deep 
// Date : 01-06-2025 
// Time : 12:02

// Solution Function
void solve() {
    int n;
    read(n);
    vi p(n);
    p[0] = 1;
    FOR(i, 1, n) p[i] = (p[i - 1] * 2) % MOD;

    vi a(n), b(n);
    read(a);
    read(b);

    int idx1 = 0, idx2 = 0;

    FOR(i, 0, n) {
        if (a[i] > a[idx1]) idx1 = i;
        if (b[i] > b[idx2]) idx2 = i;


        int ans = -1;
        if(a[idx1] > b[idx2])
            ans=(p[a[idx1]] + p[b[i - idx1]])%MOD;
        else if(a[idx1] < b[idx2])
            ans=(p[b[idx2]] + p[a[i - idx2]])%MOD;
        else
        {
            if(b[i-idx1] > a[i - idx2]) ans=(p[a[idx1]] + p[b[i - idx1]])%MOD;
            else ans=(p[b[idx2]] + p[a[i - idx2]])%MOD;
        }

        cout << ans % MOD<< " ";
    }

    cout << endl;
}


// Main Function
int32_t main() {
    fastio();
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}