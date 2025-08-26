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
// Date : 26-08-2025 
// Time : 20:22


// Solution Function
void solve() {
    int n, k;
    read(n, k);
    vi v(n);
    read(v);

    int g = 0;
    for (auto it : v) g = gcd(g, it);
    if (g > 1) {
        print(v);
        return;
    }

    if (k & 1) {
        for (auto it : v) {
            if (it & 1) cout << it + k << " ";
            else cout << it << " ";
        }
        cout << endl;
        return;
    }

    if (k == 0) {
        print(v);
        return;
    }

    auto spf = [](int x) -> int {
        if (x <= 1) return x;
        if (x % 2 == 0) return 2;
        for (int i = 3; i * i <= x; i += 2) if (x % i == 0) return i;
        return x;
    };

    int p = spf(k + 1);
    int inv = mod_exp((k % p + p) % p, p - 2, p);

    for (auto a : v) {
        int r = (a % p + p) % p;
        int need = (p - r) % p;
        int s = (need * inv) % p;
        cout << a + s * k << " ";
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