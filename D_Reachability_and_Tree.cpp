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
    int ans = 1;
    while (exp) {
        if (exp % 2 == 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
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
// Date : 23-06-2025 
// Time : 20:50

const int MAXN = 2e5 + 5;

vi adj[MAXN];
vector<pair<int, int>> ans;
int deg[MAXN];

void dfs(int u, int parent, bool dir) {
    for (auto it : adj[u]) {
        if (it == parent) continue;
        if (dir)
            ans.pb({u, it}); 
        else
            ans.pb({it, u}); 
        dfs(it, u, !dir); 
    }
}

// Solution Function
void solve() {
    int n;
    read(n);


    FOR(i,1,n+1) {
        adj[i].clear();
        deg[i] = 0;
    }
    ans.clear();

    FOR(i,0,n-1) {
        int u, v;
        read(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    int center = -1;
    FOR(i,1,n+1) {
        if (deg[i] == 2) {
            center = i;
            break;
        }
    }

    if (center == -1) {
        NO
        return;
    }


    int x = adj[center][0];
    int y = adj[center][1];

    //x -> center -> y
    ans.pb({x, center});
    ans.pb({center, y});

    
    dfs(x, center, true);
    dfs(y, center, false);

    YES
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
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
/*
██████╗░░█████╗░██████╗░███╗░░░███╗░█████╗░░██████╗██╗░░██╗██╗   ██╗░░██╗██╗░░██╗░█████╗░████████╗░█████╗░███╗░░░███╗
██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔════╝██║░░██║██║   ██║░██╔╝██║░░██║██╔══██╗╚══██╔══╝██╔══██╗████╗░████║
██████╦╝███████║██║░░██║██╔████╔██║██║░░██║╚█████╗░███████║██║   █████═╝░███████║███████║░░░██║░░░███████║██╔████╔██║
██╔══██╗██╔══██║██║░░██║██║╚██╔╝██║██║░░██║░╚═══██╗██╔══██║██║   ██╔═██╗░██╔══██║██╔══██║░░░██║░░░██╔══██║██║╚██╔╝██║
██████╦╝██║░░██║██████╔╝██║░╚═╝░██║╚█████╔╝██████╔╝██║░░██║██║   ██║░╚██╗██║░░██║██║░░██║░░░██║░░░██║░░██║██║░╚═╝░██║
╚═════╝░╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝   ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝
*/