#include <bits/stdc++.h>
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define int long long
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
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
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
// Time : 17:29

int shortestSubsequenceWithGCDx(vector<int>& A, int x) {
    map<int, int> dp; // dp[gcd] = min length to get gcd

    for (int a : A) {
        map<int, int> temp;

        // Start new subsequence with a
        int g = a;
        temp[g] = 1;

        // Extend all previous subsequences
        for (auto& it : dp) {
            int prev_g = it.first;
            int len = it.second;
            int new_g = __gcd(prev_g, a);
            int new_len = len + 1;

            if (temp.count(new_g) == 0 || temp[new_g] > new_len)
                temp[new_g] = new_len;
        }

        // Merge temp into dp
        for (auto& it : temp) {
            int g = it.first;
            int l = it.second;
            if (dp.count(g) == 0 || dp[g] > l)
                dp[g] = l;
        }
    }

    return dp.count(x) ? dp[x] : -1;
}


// Solution Function
void solve() {
    int n;
    read(n);
    vi v(n);
    read(v);

    int x = 0;
    int cnt = 0;
    FOR(i, 0, n) x = gcd(x, v[i]);
    FOR(i, 0, n) cnt += (v[i] != x);

    if (cnt < n) cout << cnt << endl;
    else {
        cout << (shortestSubsequenceWithGCDx(v, x) - 1) + (n - 1) << endl;
    }
    // dbg(shortestSubsequenceWithGCDx(v,x));
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
