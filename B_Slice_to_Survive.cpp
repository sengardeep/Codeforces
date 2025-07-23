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
#define MOD_INV(x) mod_exp(x, MOD - 2, MOD)
#define MAX 100000

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
// Date : 26-05-2025
// Time : 11:22

// Solution Function
void solve()
{
    int x, y, a, b;
    read(x, y, a, b);
    int ans = 1;
    a=min(a,x-a+1);
    b=min(b,y-b+1);
    // a
    {
        int xx=a,yy=y;
        while (xx != 1)
        {
            ans++;
            xx = ceil((float)xx / 2);
        }

        while (yy != 1)
        {
            ans++;
            yy = ceil((float)yy / 2);
        }

        // int res=1;
        // xx=x-a+1,yy=y;
        // while (xx != 1)
        // {
        //     res++;
        //     xx = ceil((float)xx / 2);
        // }

        // while (yy != 1)
        // {
        //     res++;
        //     yy = ceil((float)yy / 2);
        // }
        // ans=min(res,ans);
    }
    //b
    {
        int res=1;
        int xx=x,yy=b;
        while (xx != 1)
        {
            res++;
            xx = ceil((float)xx / 2);
        }

        while (yy != 1)
        {
            res++;
            yy = ceil((float)yy / 2);
        }
        ans = min(ans,res);


        // res=1;
        // xx=x,yy=y-b+1;
        // while (xx != 1)
        // {
        //     res++;
        //     xx = ceil((float)xx / 2);
        // }

        // while (yy != 1)
        // {
        //     res++;
        //     yy = ceil((float)yy / 2);
        // }
        // ans = min(ans,res);

    }
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