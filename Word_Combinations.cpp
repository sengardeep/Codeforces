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
template <typename T>
void dbg_vec(const T &v)
{
    cerr << "[ ";
    for (const auto &x : v)
        cerr << x << " ";
    cerr << "]" << endl;
}

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
// Combatronics
// Uncomment if needed

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
// Date : 13-08-2025
// Time : 10:44
// We replace the exponential backtracking (which TLEs and is incorrect for this problem)
// with a linear DP over the string using a Trie built from the dictionary.
//
// Problem model (as in CF "Word Combinations"):
// - Count the number of ways to form the string s by concatenating given words
//   in order, from left to right. We match only prefixes at each position.
// - Answer is the number of decompositions modulo 1e9+7.
//
// Approach:
// - Build a Trie from all words. Each path corresponds to a prefix we can match quickly.
// - Let dp[i] be the number of ways to form s[0..i-1]. dp[0] = 1 (empty prefix).
// - For each starting index i, walk the Trie following s[i], s[i+1], ...
//   Every time we end at a terminal node, add dp[i] to dp[j+1].
// - Complexity: O(|s| * average branching along matches) ~ O(|s| + total matches), fast enough.
//
// Notes:
// - Assumes lowercase letters 'a'..'z' as in the original problem constraints.
// - If characters outside 'a'..'z' appear in s or words, they won't be matched.
//
// Implementation:

// Solution Function
void solve()
{
    // Read string and dictionary
    string s;
    int n;
    read(s, n);
    vector<string> v(n);
    read(v);

    // Trie node: 26 children + terminal flag
    struct Node {
        int nxt[26];
        bool end;
        Node() : end(false) { memset(nxt, -1, sizeof(nxt)); }
    };

    // Trie storage (node 0 = root)
    vector<Node> trie(1);

    // Insert word into trie
    auto insert = [&](const string& w) {
        int cur = 0;
        for (char ch : w) {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26) return; // ignore invalid characters
            if (trie[cur].nxt[idx] == -1) {
                trie[cur].nxt[idx] = (int)trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[idx];
        }
        trie[cur].end = true;
    };

    // Build the trie from all words
    for (const auto& w : v) insert(w);

    // DP over s: dp[i] = ways to form prefix of length i
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (size_t i = 0; i < s.size(); ++i) {
        if (dp[i] == 0) continue; // no ways to reach i -> skip
        int cur = 0;
        for (size_t j = i; j < s.size(); ++j) {
            int idx = s[j] - 'a';
            if (idx < 0 || idx >= 26) break;         // unsupported char
            cur = trie[cur].nxt[idx];
            if (cur == -1) break;                    // no further match
            if (trie[cur].end) {                     // found a word ending at j
                dp[j + 1] += dp[i];
                if (dp[j + 1] >= MOD) dp[j + 1] -= MOD;
            }
        }
    }

    // Print the total number of ways to form s
    cout << dp[s.size()];
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
    // cin >> t;
    while (t--)
        solve();
    return 0;
}