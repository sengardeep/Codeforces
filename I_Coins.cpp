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
// Date : 31-07-2025 
// Time : 18:42

double v[3000];
double dp[3000][3000];

// double helper(int idx, int count, int n) {
//     if (count < 0) return 0;
//     if (idx < 0) return (count == 0) ? 1 : 0;

//     if (dp[idx][count] != -1) return dp[idx][count];

//     // take
//     double take = v[idx] * helper(idx - 1, count - 1, n);
//     // skip
//     double skip = (1.0 - v[idx]) * helper(idx - 1, count, n);

//     return dp[idx][count] = take + skip;
// }

// Solution Function
void solve() {
    int n;
    read(n);
    FOR(i, 1, n+1) read(v[i]);
    
    // dp[i][j] denotes probabilty of getting j heads till i index
    dp[0][0]=1;
    FOR(i,1,n+1){
        FOR(j,0,i+1){
            if(j==0) dp[i][j]=(1.0-v[i])*(dp[i-1][j]);
            else{
                double headP = v[i]*dp[i-1][j-1];
                double tailP = (1.0-v[i])*dp[i-1][j];
                dp[i][j]=headP+tailP;
            }
        }
    } 

    double ans = 0;
    int x = (n + 1) / 2;
    for (int heads = x; heads <= n; ++heads) {
        ans += dp[n][heads];
    }
    cout << fixed << setprecision(10) << ans << endl;
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