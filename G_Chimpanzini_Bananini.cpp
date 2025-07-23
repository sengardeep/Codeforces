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

// Modular Arithmetic
class ModInt {
public:
    int val;
    ModInt(int v = 0) : val(v % MOD) { if (val < 0) val += MOD; }
    ModInt operator+(const ModInt &other) const { return ModInt(val + other.val); }
    ModInt operator-(const ModInt &other) const { return ModInt(val - other.val); }
    ModInt operator*(const ModInt &other) const { return ModInt(val * other.val); }
    ModInt pow(int exp) const {
        ModInt base = *this, res = 1;
        while (exp) {
            if (exp % 2) res = res * base;
            base = base * base;
            exp /= 2;
        }
        return res;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt operator/(const ModInt &other) const { return *this * other.inv(); }
};

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
// Date : 14-04-2025 
// Time : 12:17


// Solution Function
int find(vi &v)
{
    int ans=0;
    FOR(i,0,v.size())
    {
        ans+=(v[i]*(i+1));
    }
    return ans;
}
void solve() {
    int q;
    read(q);
    vector<int> v;
    while(q--)
    {
        int x;
        read(x);
        if(x == 1)
        {
            int a=v.back();
            v.pop_back();
            v.insert(v.begin(),a);
            cout<<find(v)<<endl;
        }
        else if(x==2)
        {
            reverse(all(v));
            cout<<find(v)<<endl;
        }
        else 
        {
            int a;
            read(a);
            v.pb(a);
            cout<<find(v)<<endl;
        }
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