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
// Date : 10-07-2025
// Time : 17:52

// Solution Function
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    read(v);
    int mx = *max_element(v.begin(), v.end());
    int sm = accumulate(v.begin(), v.end(), 0LL);
    if (sm & 1)
    {
        cout << -1 << endl;
        return;
    }
    if (mx * 2 > sm)
    {
        cout << -1 << endl;
        return;
    }
    int c = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        c += v[i];
        if (c * 2 == sm)
        {
            cout << 1 << endl;
            print(v);
            return;
        }
        else if (c * 2 > sm)
        {
            l = i;
            break;
        }
    }
    cout << 2 << endl;
    vector<int> v1(n), v2(n);
    if (c - v[l] <= sm - c)
    {
        int k = sm - c;
        int s1 = sm - k;
        int c1 = 0;
        for (int i = l + 1; i < n; i++)
        {
            v1[i] = v[i];
        }
        for (int i = 0; i <= l; i++)
        {
            c1 += v[i];
            if (c1 * 2 == s1)
            {
                int x = i, y = i + 1;
                while (k > 0)
                {
                    int b = min(v[x], v[y]);
                    if (b * 2 >= k)
                    {
                        v[x] -= k / 2;
                        v[y] -= k / 2;
                        v1[x] += k / 2;
                        v1[y] += k / 2;
                        k = 0;
                        break;
                    }
                    else
                    {
                        k -= b * 2;
                        v[x] -= b;
                        v[y] -= b;
                        v1[x] += b;
                        v1[y] += b;
                        if (v[x] == 0)
                            x--;
                        if (v[y] == 0)
                            y++;
                    }
                }
                for (int j = 0; j <= l; j++)
                {
                    v2[j] = v[j];
                }
                break;
            }
            else if (c1 * 2 > s1)
            {
                int d1 = c1 - (s1 - c1);
                if (d1 > v[i])
                {
                    c1 = v[i] + (s1 - c1);
                    int d1 = c1 - (s1 - c1);
                    v1[i] += d1;
                    v[i] -= d1;
                    k -= d1;
                    int x = i - 1, y = i;
                    while (k > 0)
                    {
                        int b = min(v[x], v[y]);
                        if (b * 2 >= k)
                        {
                            v[x] -= k / 2;
                            v[y] -= k / 2;
                            v1[x] += k / 2;
                            v1[y] += k / 2;
                            k = 0;
                            break;
                        }
                        else
                        {
                            k -= b * 2;
                            v[x] -= b;
                            v[y] -= b;
                            v1[x] += b;
                            v1[y] += b;
                            if (v[x] == 0)
                                x--;
                            if (v[y] == 0)
                                y++;
                        }
                    }
                    for (int j = 0; j <= l; j++)
                    {
                        v2[j] = v[j];
                    }
                    break;
                }
                v1[i] += d1;
                v[i] -= d1;
                k -= d1;
                int x = i, y = i + 1;
                while (k > 0)
                {
                    int b = min(v[x], v[y]);
                    if (b * 2 >= k)
                    {
                        v[x] -= k / 2;
                        v[y] -= k / 2;
                        v1[x] += k / 2;
                        v1[y] += k / 2;
                        k = 0;
                        break;
                    }
                    else
                    {
                        k -= b * 2;
                        v[x] -= b;
                        v[y] -= b;
                        v1[x] += b;
                        v1[y] += b;
                        if (v[x] == 0)
                            x--;
                        if (v[y] == 0)
                            y++;
                    }
                }
                for (int j = 0; j <= l; j++)
                {
                    v2[j] = v[j];
                }
                break;
            }
        }
    }
    else
    {
        int k = c - v[l];
        int s1 = sm - k;
        int c1 = 0;
        for (int i = 0; i < l; i++)
        {
            v1[i] = v[i];
        }
        for (int i = l; i < n; i++)
        {
            c1 += v[i];
            if (c1 * 2 == s1)
            {
                int x = i, y = i + 1;
                while (k > 0)
                {
                    int b = min(v[x], v[y]);
                    if (b * 2 >= k)
                    {
                        v[x] -= k / 2;
                        v[y] -= k / 2;
                        v1[x] += k / 2;
                        v1[y] += k / 2;
                        k = 0;
                        break;
                    }
                    else
                    {
                        k -= b * 2;
                        v[x] -= b;
                        v[y] -= b;
                        v1[x] += b;
                        v1[y] += b;
                        if (v[x] == 0)
                            x--;
                        if (v[y] == 0)
                            y++;
                    }
                }
                for (int j = l; j < n; j++)
                {
                    v2[j] = v[j];
                }
                break;
            }
            else if (c1 * 2 > s1)
            {
                int d1 = c1 - (s1 - c1);
                if (d1 > v[i])
                {
                    c1 = v[i] + (s1 - c1);
                    int d1 = c1 - (s1 - c1);
                    v1[i] += d1;
                    v[i] -= d1;
                    k -= d1;
                    int x = i - 1, y = i;
                    while (k > 0)
                    {
                        int b = min(v[x], v[y]);
                        if (b * 2 >= k)
                        {
                            v[x] -= k / 2;
                            v[y] -= k / 2;
                            v1[x] += k / 2;
                            v1[y] += k / 2;
                            k = 0;
                            break;
                        }
                        else
                        {
                            k -= b * 2;
                            v[x] -= b;
                            v[y] -= b;
                            v1[x] += b;
                            v1[y] += b;
                            if (v[x] == 0)
                                x--;
                            if (v[y] == 0)
                                y++;
                        }
                    }
                    for (int j = l; j < n; j++)
                    {
                        v2[j] = v[j];
                    }
                    break;
                }
                v1[i] += d1;
                v[i] -= d1;
                k -= d1;
                int x = i, y = i + 1;
                while (k > 0)
                {
                    int b = min(v[x], v[y]);
                    if (b * 2 >= k)
                    {
                        v[x] -= k / 2;
                        v[y] -= k / 2;
                        v1[x] += k / 2;
                        v1[y] += k / 2;
                        k = 0;
                        break;
                    }
                    else
                    {
                        k -= b * 2;
                        v[x] -= b;
                        v[y] -= b;
                        v1[x] += b;
                        v1[y] += b;
                        if (v[x] == 0)
                            x--;
                        if (v[y] == 0)
                            y++;
                    }
                }
                for (int j = l; j < n; j++)
                {
                    v2[j] = v[j];
                }
                break;
            }
        }
    }
    print(v1);
    print(v2);
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