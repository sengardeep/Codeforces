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
// Time : 17:36


// Solution Function
void solve() {
    vi sum(3,0);
    vvi v(3,vi(3,0));
    FOR(i,0,3) read(v[i]);
    int mini=INT_MAX;
    FOR(i,0,3)
    {
        FOR(j,0,3)
        {
            if(v[i][j]!=0)
            mini=min(mini,v[i][j]);
            sum[i] += v[i][j];
        }
    }
    // dbg_vec(sum);
    vi sum2=sum;
    int diff=abs(sum[0]-sum[1]);
    vi num={mini,mini+diff,mini+diff+diff};
    sort(all(sum2));
    reverse(all(sum2));

    while(true)
    {
        int s = accumulate(all(num),0);
        if(sum2[0]+num[0] == s) 
        break;
        else 
        {
            FOR(i,0,3) num[i]+=1;
        }
    }

    sort(all(num));
    // dbg_vec(num);
    if(sum[0]>sum[1]) {
    v[0][0]=num[0];
    v[1][1]=num[1];
    v[2][2]=num[2];}
    else{
    v[2][2]=num[0];
    v[1][1]=num[1];
    v[0][0]=num[2];}

    FOR(i,0,3)  print(v[i]);
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