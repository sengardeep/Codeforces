#include <bits/stdc++.h>
// #define int long long
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
// Created by Deep 
// Date : 04-06-2025 
// Time : 11:21
const int MOD = 1e9 + 7;

class ModInt {
public:
    int val;
    ModInt(long long v = 0) {
        val = int(v % MOD);
        if (val < 0) val += MOD;
    }
    ModInt operator+(const ModInt &other) const { return ModInt(val + other.val); }
    ModInt operator-(const ModInt &other) const { return ModInt(val - other.val); }
    ModInt operator*(const ModInt &other) const { return ModInt(1LL * val * other.val); }
    ModInt pow(long long exp) const {
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

ostream& operator<<(ostream &os, const ModInt &m) {
    return os << m.val;
}

// Solution Function
void solve() {
    int x, y, n;
    cin >> x >> y >> n;

    vector<ModInt> v(6);
    v[0] = x;
    v[1] = y;
    for (int i = 2; i < 6; i++)
        v[i] = v[i - 1] - v[i - 2];

    int index = (n - 1) % 6;
    if (index < 0) index += 6;

    cout << v[index] << endl;
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