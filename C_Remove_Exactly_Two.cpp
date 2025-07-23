#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;

// Common Macros
#define vi vector<int>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define INF LLONG_MAX
#define MAX 100000

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

void addEdge(vvi &tree, int u, int v)
{
    tree[u].pb(v);
    tree[v].pb(u);
}

// Solution Function
void solve()
{
    int n;
    read(n);
    vvi list(n + 1);
    vi degree(n + 1);

    FOR(i, 0, n - 1)
    {
        int u, v;
        read(u, v);
        addEdge(list, u, v);
        degree[u]++;
        degree[v]++;
    }

    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }

    int max1 = 0, max2 = 0;
    FOR(i, 1, n + 1)
    {
        if (degree[i] > max1)
        {
            max2 = max1;
            max1 = degree[i];
        }
        else if (degree[i] > max2)
        {
            max2 = degree[i];
        }
    }

    int result = n - max1 - max2 + 2;

    cout << result << endl;
}

// Main Function
int32_t main()
{
    fastio();

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
