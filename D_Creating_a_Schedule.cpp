#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;

// Common Macros
#define vi vector<int>
#define vvi vector<vi>
#define all(w) w.begin(), w.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define INF LLONG_MAX
#define MOD_INV(x) mod_exp(x, MOD - 2, MOD)
#define MAX 100000

// Debugging Helpers
template <typename T> void dbg_vec(const T &w) {
    cerr << "[ ";
    for (const auto &x : w) cerr << x << " ";
    cerr << "]" << endl;
}

// Utility Functions
int gcd(int v, int b) { return b ? gcd(b, v % b) : v; }
int lcm(int v, int b) { return (v / gcd(v, b)) * b; }
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
template<typename T> void read(T& x) { cin >> x; }
template<typename T, typename... Args>
void read(T& first, Args&... rest) {
    cin >> first;
    read(rest...);
}
template<typename T> void read(vector<T>& w) { for (auto &x : w) cin >> x; }
template<typename T> void print(const vector<T>& w) { for (auto &x : w) cout << x << " "; cout << endl; }


// Created by Deep 
// Date : 03-06-2025 
// Time : 20:51

// Solution Function
void solve() {
    int n, m;
    read(n, m);
    vi a(m); 
    read(a);

    vector<pair<int, int>> w(m);
    FOR(i, 0, m) {
        int grp = a[i] / 100;
        w[i] = {grp, a[i]};
    }

    sort(all(w), [](pair<int, int> &a,pair<int, int> &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vi key(m), val(m);
    FOR(i, 0, m) {
        key[i] = w[i].first;
        val[i] = w[i].second;
    }

    vi diff(n);
    FOR(i, 0, n) {
        diff[i] = abs(key[i] - key[m - 1 - i]);
    }

    vi pre(n + 1, 0);
    FOR(i, 1, n + 1) pre[i] = pre[i - 1] + diff[i - 1];

    int k1 = 0, maxi = -1;
    FOR(k, 0, n + 1) {
        int val_sum = pre[k] + pre[n - k];
        if (val_sum > maxi) {
            maxi = val_sum;
            k1 = k;
        }
    }

    int k = k1;
    vi a1(n), b(n);
    int idx = 0;
    FOR(i, 0, k) a1[idx++] = val[i];
    FOR(i, m - (n - k), m) a1[idx++] = val[i];

    idx = 0;
    FOR(i, 0, n - k) b[idx++] = val[i];
    FOR(i, m - k, m) b[idx++] = val[i];

    FOR(i, 0, n) {
        int a_val = a1[i];
        int b_val = b[n - 1 - i];
        FOR(j, 0, 6) {
            cout << (j % 2 == 0 ? a_val : b_val);
            if (j < 5) cout << " ";
        }
        cout << endl;
    }
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
