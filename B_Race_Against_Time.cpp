#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;
using namespace __gnu_pbds;

// Common Macros
#define _GLIBCXX_INCLUDE_NEXT_C_HEADERS
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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
//Combatronics
//Uncomment if needed

// const int N = 1e6 + 1;
// vector<int> fact(N,1);
// vector<int> inv_fact(N,1);
// void factorial(){
//     for(int i=2;i<N;i++){
//         fact[i]=(fact[i-1]*i)%MOD;
//     }
// }
// void invFactorial(){
//     inv_fact[N-1]=MOD_INV(fact[N-1]);
//     for(int i=N-2;i>=0;i--){
//         inv_fact[i]=(inv_fact[i+1]*(i+1))%MOD;
//     }
// }
// int nCr(int n,int r,int mod){
//     return (((fact[n]*inv_fact[n-r])%mod)*inv_fact[r])%mod;
// }

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
// Date : 12-08-2025 
// Time : 18:26


// Solution Function
void solve() {
    double h, m, s, t1, t2;
    read(h, m, s, t1, t2);

    auto norm = [](double x) {
        x = fmod(x, 12.0);
        if (x < 0) x += 12.0;
        return x;
    };

    // Positions on [0,12)
    double hp = norm((h == 12 ? 0 : h) + m / 60.0 + s / 3600.0);
    double mp = norm((m + s / 60.0) / 5.0);
    double sp = norm(s / 5.0);

    vector<double> p = {hp, mp, sp};
    sort(all(p));

    double a = norm(t1);
    double b = norm(t2);

    const double EPS = 1e-9;
    auto is_on_hand = [&](double x) {
        for (double v : p) if (fabs(x - v) < EPS) return true;
        return false;
    };
    if (is_on_hand(a) || is_on_hand(b)) {
        NO
        return;
    }

    auto between = [&](double x, double l, double r) {
        return x > l + EPS && x < r - EPS;
    };

    bool ok = false;
    if (between(a, p[0], p[1]) && between(b, p[0], p[1])) ok = true;
    if (between(a, p[1], p[2]) && between(b, p[1], p[2])) ok = true;

    auto wrap_between = [&](double x) {
        double l = p[2], r = p[0] + 12.0;
        if (x < l) x += 12.0;
        return x > l + EPS && x < r - EPS;
    };
    if (wrap_between(a) && wrap_between(b)) ok = true;

    if (ok) {
        YES
    } else {
        NO
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
    // cin >> t;
    while (t--) solve();
    return 0;
}