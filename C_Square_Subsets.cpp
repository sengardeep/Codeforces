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
// Date : 22-08-2025 
// Time : 23:17

int n;
vi v;

// Counts non-empty subsets whose product is a perfect square.
// Idea: represent each number a by a bitmask of parity (odd/even) exponents of primes <= 70.
// A product is a perfect square iff all prime exponents are even => combined mask == 0.
void solve() {
    read(n);
    v.resize(n);
    read(v);

    // Frequency of each value in [1..70] (problem constraint).
    // Values outside this range do not affect the classic solution and are ignored.
    vector<int> cnt(71, 0);
    for (int x : v) if (x >= 1 && x <= 70) cnt[x]++;

    // List of primes up to 70 and DP state size (2^number_of_primes).
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
    int P = (int)primes.size();
    int SZ = 1 << P;

    // Precompute a mask for each a in [1..70]:
    // bit j is 1 if prime primes[j] divides a an odd number of times (mod 2 exponent).
    vector<int> valMask(71, 0);
    for (int a = 1; a <= 70; ++a) {
        int x = a;
        int mask = 0;
        for (int j = 0; j < P; ++j) {
            int p = primes[j];
            int c = 0;
            // Count exponent of p in a, only keep parity (c ^= 1).
            while (x % p == 0) { x /= p; c ^= 1; }
            if (c) mask ^= (1 << j);
        }
        valMask[a] = mask; // "square-free kernel" parity mask of a
    }

    // dp[m] = number of ways to pick elements so that the XOR of masks equals m.
    vector<int> dp(SZ, 0);
    dp[0] = 1; // empty subset

    // Process each value a by its count.
    for (int a = 1; a <= 70; ++a) {
        if (cnt[a] == 0) continue;

        // From cnt[a] identical items:
        // - number of ways to pick an even count = 2^(cnt[a]-1)
        // - number of ways to pick an odd  count = 2^(cnt[a]-1)
        int even = mod_exp(2, cnt[a] - 1);
        int odd = even;

        vector<int> ndp(SZ, 0);
        for (int m = 0; m < SZ; ++m) {
            if (dp[m] == 0) continue;

            // Pick even copies of 'a': mask doesn't change.
            ndp[m] = (ndp[m] + (long long)dp[m] * even) % MOD;

            // Pick odd copies of 'a': mask flips by valMask[a].
            int nm = m ^ valMask[a];
            ndp[nm] = (ndp[nm] + (long long)dp[m] * odd) % MOD;
        }
        dp.swap(ndp);
    }

    // dp[0] counts all subsets whose product is a perfect square (including empty).
    int ans = (dp[0] - 1 + MOD) % MOD; // exclude empty subset
    cout << ans;
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