/*
██████╗░░█████╗░██████╗░███╗░░░███╗░█████╗░░██████╗██╗░░██╗██╗   ░██████╗██╗░░██╗██╗░░░██╗██████╗░██╗░░░██╗
██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔════╝██║░░██║██║   ██╔════╝██║░░██║██║░░░██║██╔══██╗██║░░░██║
██████╦╝███████║██║░░██║██╔████╔██║██║░░██║╚█████╗░███████║██║   ╚█████╗░███████║██║░░░██║██████╔╝██║░░░██║
██╔══██╗██╔══██║██║░░██║██║╚██╔╝██║██║░░██║░╚═══██╗██╔══██║██║   ░╚═══██╗██╔══██║██║░░░██║██╔══██╗██║░░░██║
██████╦╝██║░░██║██████╔╝██║░╚═╝░██║╚█████╔╝██████╔╝██║░░██║██║   ██████╔╝██║░░██║╚██████╔╝██║░░██║╚██████╔╝
╚═════╝░╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝   ╚═════╝░╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝░╚═════╝░
*/
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
#define MAX 100000
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
// Date : 28-06-2025
// Time : 13:32
const int N = 1e6 + 1;
vi spf(N);
int prime_count[N]; // global, reused
vector<int> used_primes;

void sieve() {
    iota(spf.begin(), spf.end(), 0);  //This function fills the value from 0 to size-1 in their corresponding indices
    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i * 2; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void factorize(int num) {
    while (num > 1) {
        int p = spf[num];
        if (prime_count[p] == 0) used_primes.pb(p);
        while (num % p == 0) {
            prime_count[p]++;
            num /= p;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto &x : v) cin >> x;

    for (int x : v) factorize(x);

    for (int p : used_primes) {
        if (prime_count[p] % n != 0) {
            NO;
            for (int q : used_primes) prime_count[q] = 0;
            used_primes.clear();
            return;
        }
    }

    YES;
    for (int p : used_primes) prime_count[p] = 0;
    used_primes.clear();
}


// Main Function
int32_t main()
{
    fastio();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
██████╗░░█████╗░██████╗░███╗░░░███╗░█████╗░░██████╗██╗░░██╗██╗   ██╗░░██╗██╗░░██╗░█████╗░████████╗░█████╗░███╗░░░███╗
██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔════╝██║░░██║██║   ██║░██╔╝██║░░██║██╔══██╗╚══██╔══╝██╔══██╗████╗░████║
██████╦╝███████║██║░░██║██╔████╔██║██║░░██║╚█████╗░███████║██║   █████═╝░███████║███████║░░░██║░░░███████║██╔████╔██║
██╔══██╗██╔══██║██║░░██║██║╚██╔╝██║██║░░██║░╚═══██╗██╔══██║██║   ██╔═██╗░██╔══██║██╔══██║░░░██║░░░██╔══██║██║╚██╔╝██║
██████╦╝██║░░██║██████╔╝██║░╚═╝░██║╚█████╔╝██████╔╝██║░░██║██║   ██║░╚██╗██║░░██║██║░░██║░░░██║░░░██║░░██║██║░╚═╝░██║
╚═════╝░╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝   ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝
*/