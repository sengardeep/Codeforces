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
// Date : 04-06-2025 
// Time : 10:07


// Solution Function
void solve() {
    int n;
    read(n);
    vi v(n);
    read(v);

    bool flag=true;
    int count=0;
    FOR(i,0,n-1)
    {
        if(v[i+1] < v[i])
        {
            int idx=i+1;
            count=1;
            while(idx<n-1 && v[idx]<=v[idx+1] && (v[idx] < v[0]))
            {
                count++;
                idx++;
            }

            if(idx < n && v[idx] == v[0])
            {
                FOR(i,idx,n)
                {
                    if(v[i]!=v[0]) 
                    {
                        flag=false;
                        break;
                    }
                    else 
                    {
                        count++;
                        idx++;
                    }
                }
                count-=1;
            }
            if(idx < n-1 || (idx<=n-1 && v[idx] > v[0])) flag=false;
            break;
        }
    }

    if(flag) cout<<count<<endl;
    else cout<<-1<<endl;

}

// Main Function
int32_t main() {
    fastio();
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}