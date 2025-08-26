#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define INF LLONG_MAX
#define MOD_INV(x) mod_exp(x, MOD - 2, MOD)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T> void read(T& x) { cin >> x; }
template<typename T, typename... Args>
void read(T& first, Args&... rest) {
    cin >> first;
    read(rest...);
}
template<typename T> void read(vector<T>& v) { for (auto &x : v) cin >> x; }
template<typename T> void print(const vector<T>& v) { for (auto &x : v) cout << x << " "; cout << endl; }

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

pair<int,int> bfs(int start, int skip, vvi& adj) { 
    int n = adj.size();
    vector<int> dist(n, -1), par(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    par[start] = skip; 
    int last = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        last = u;
        for (int v : adj[u]) {
            if (v == par[u]) continue;
            if (dist[v] != -1) continue;
            par[v] = u;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return {dist[last], last};
}

// Created by Deep 
// Date : 26-08-2025 
// Time : 21:05


// Solution Function
void solve() {
    int n;
    read(n);
    vvi adj(n);
    vi deg(n, 0);
    FOR(i, 1, n) {
        int u, v; 
        read(u, v);
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++; 
        deg[v]++;
    }

    bool path = true;
    FOR(i, 0, n) if (deg[i] > 2) { path = false; break; }
    if (path) {
        cout << -1 << endl;
        return;
    }

    int b = -1;
    FOR(i, 0, n) {
        if (deg[i] > 2) { b = i; break; }
    }

    // pick deepest from b
    vector<pair<int,int>> ans; // {depth, neighbor}
    for (int v : adj[b]) {
        auto res = bfs(v, b, adj);
        ans.push_back({res.first, v});
    }

    sort(all(ans), [&](const auto& A, const auto& B){
        if (A.first != B.first) return A.first > B.first;
        return A.second < B.second;
    });

    int a = ans[0].second;
    int c = ans[1].second;

    cout << (a + 1) << ' ' << (b + 1) << ' ' << (c + 1) << endl;
}

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