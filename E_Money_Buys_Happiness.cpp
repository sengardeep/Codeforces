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
// Date : 24-08-2025 
// Time : 22:51

int n, x;
const int M = 1e5 + 1; // Upper bound on total happiness tracked by DP (should exceed sum(h))
vi c, h;

// Solution Function
void solve() {
    read(n, x);
    c.resize(n);
    h.resize(n);
    FOR(i, 0, n) read(c[i], h[i]);

    /*
      State modeling:
      - We process months/items in order (i = 1..n). Item i (1-indexed) can be bought only
        using money earned strictly before month i (j < i), never from month i or later.
      - dp[j] = best way to achieve total happiness = j so far, stored as:
          {months_used, remaining_money}
        where:
          months_used = total number of months whose salary has already been "consumed"
                        to pay for the chosen items so far.
          remaining_money = cash left after paying for those items using 'months_used' months.

      Invariants:
      - 0 <= remaining_money < x always (we always roll forward full months when short).
      - For fixed happiness j, we keep the lexicographically best pair:
          minimize months_used; if tie, maximize remaining_money.

      Why this works:
      - months_used tells how far into the timeline we have advanced our spending.
      - To buy the next item at month i, we may need to advance by some extra months 'need'
        so that the accumulated salary covers its cost, but we must not reach month i
        (cannot use current month's salary), hence the constraint: months_used + need <= i - 1.
    */

    // Initialize: happiness 0 can be achieved with 0 months used and 0 money.
    vector<pair<int, int>> dp(M, {INF, 0});
    dp[0] = {0, 0};

    // Process each item/month in chronological order (1-indexed for clarity).
    for (int i = 1; i <= n; ++i) {
        int ci = c[i - 1], hi = h[i - 1];

        // 0/1 knapsack backward iteration on happiness to avoid reusing the same item twice.
        for (int j = M - 1; j >= 0; --j) {
            if (dp[j].first == INF) continue; // unreachable happiness sum

            int nj = j + hi;          // new happiness after taking item i
            if (nj >= M) continue;    // skip if outside DP bounds

            int rem = dp[j].second;   // current remaining money for happiness j
            int need = 0;
            // If not enough money to pay 'ci', advance by the minimal number of full months
            // (each month adds +x) to cover the shortfall.
            if (ci > rem) need = (ci - rem + x - 1) / x; // ceil((ci - rem)/x)

            int nm = dp[j].first + need; // months used after advancing 'need' months

            // Key constraint: cannot use month i's salary for month i's item.
            // So total months used after advancing must be at most i - 1.
            if (nm <= i - 1) {
                // Pay now: money after advancing 'need' months and buying cost 'ci'
                int nrem = rem + need * x - ci;

                // Keep the best timeline: fewer months_used or, if tie, more remaining money.
                auto &cur = dp[nj];
                if (nm < cur.first || (nm == cur.first && nrem > cur.second))
                    cur = {nm, nrem};
            }
        }
    }

    // The answer is the maximum achievable happiness with any feasible timeline.
    int ans = 0;
    for (int j = M - 1; j >= 0; --j) {
        if (dp[j].first != INF) { ans = j; break; }
    }
    cout << ans << '\n';
}

/*
Gotchas and notes:
- M should be >= sum(h) + 1 to be safe; using a fixed 1e5+1 works only if sum(h) <= 1e5.
  Consider computing M dynamically from input to avoid wasted memory/time.
- Money arithmetic may overflow 32-bit if x or need are large; consider int64_t for safety:
    pair<int,int64_t> and nrem as int64_t.
- Time complexity: O(n * M). Optimize M or prune unreachable states if needed.
*/

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