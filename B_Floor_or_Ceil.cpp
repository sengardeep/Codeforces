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
// Date : 15-03-2025
// Time : 20:29

// Solution Function
void solve()
{
    int n, x, y;
    read(n, x, y);
    // Find minimum (up for even , low for odd)
    int step1 = x, step2 = y;
    int copy = n;
    bool flag = true;
    while (step1 > 0 && step2 > 0)
    {
        if (copy & 1)
        {
            copy /= 2;
            step1--;
        }
        else
        {
            copy =copy/2;
            step2--;
        }
        if (copy == 0 || (copy == 1 && step1 > 0))
        {
            cout << 0 << " ";
            step1 = 0;
            step2 = 0;
            flag = false;
            break;
        }
        else if (copy == 1 && step1 == 0)
        {
            cout << 1 << " ";
            step1 = 0;
            step2 = 0;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        if (copy == 1 && step1 == 0)
        {
            cout << 1 << " ";
            flag = false;
        }
        else if (copy == 0 || (copy == 1 && step1 > 0))
        {
            cout << 0 << " ";
            flag = false;
        }
        while (step1-- > 0)
            copy /= 2;
        while (step2-- > 0)
            copy = (copy + 1) / 2;
        if (flag)
            cout << copy << " ";
    }
    // Find maximum (low for even , up for odd)
    step1 = x, step2 = y;
    copy = n;
    while (step1 > 0 && step2 > 0)
    {
        if (copy & 1)
        {
            copy = (copy + 1) / 2;
            step2--;
        }
        else
        {
            copy /= 2;
            step1--;
        }
        if (copy == 0 || (copy == 1 && step1 > 0))
        {
            cout << 0 << endl;
            return;
        }
        else if (copy == 1 && step1 == 0)
        {
            cout << 1 << endl;
            return;
        }
    }
    if (copy == 1 && step1 == 0)
    {
        cout << 1 << endl;
        return;
    }
    else if (copy == 0 || (copy == 1 && step1 > 0))
    {
        cout << 0 << endl;
        return;
    }
    while (step1-- > 0)
        copy /= 2;
    while (step2-- > 0)
        copy = (copy + 1) / 2;
    cout << copy << endl;
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