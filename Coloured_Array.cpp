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
// Date : 18-06-2025
// Time : 21:16
const int MAXN = 200005;

vi adj[MAXN];
int matchL[MAXN], matchR[MAXN], vis[MAXN];

bool bpm(int u, int visit_id)
{
    for (int v : adj[u])
    {
        if (vis[v] == visit_id)
            continue;
        vis[v] = visit_id;
        if (matchR[v] == -1 || bpm(matchR[v], visit_id))
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int check(int L, int R)
{
    fill(matchL, matchL + L, -1);
    fill(matchR, matchR + R + 2, -1);
    fill(vis, vis + R + 2, 0);
    int res = 0, visit_id = 1;
    for (int u = 0; u < L; ++u)
    {
        if (matchL[u] == -1)
        {
            if (bpm(u, visit_id++))
                ++res;
        }
    }
    return res;
}

// Solution Function
void solve()
{
    int n;
    read(n);
    vi v(2 * n);
    read(v);

    map<int, int> mp;
    vector<pair<int, int>> bad_pairs;
    vector<bool> used(n + 2, false);

    for (int i = 0; i < 2 * n; i += 2)
    {
        int x = v[i], y = v[i + 1];
        if (x == y)
        {
            mp[x]++;
        }
        else
        {
            bad_pairs.emplace_back(x, y);
        }
    }

    for (auto &it : mp)
    {
        int val = it.first;
        int count = it.second;
        used[val] = true;
        for (int i = 1; i < count; ++i)
        {
            bad_pairs.emplace_back(val, val); 
        }
    }

    int M = bad_pairs.size();
    FOR(i,0,M)
        adj[i].clear();

   
    FOR(i,0,M)
    {
        int x = bad_pairs[i].first, y = bad_pairs[i].second;
        if (!used[x])
            adj[i].pb(x);
        if (x != y && !used[y])
            adj[i].pb(y);
    }

    int match = check(M, n + 1);
    int ans = 2 * M - match;
    cout << ans << endl;
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
