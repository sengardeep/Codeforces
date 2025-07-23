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
// Date : 05-06-2025 
// Time : 21:08


// Solution Function
void solve() {
    int n;
    read(n);
    vi v1,v2;
    int score1=0,score2=0;
    int last=0;
    FOR(i,0,n)
    {
        int x;
        read(x);
        if(i==n-1) last=x;

        if(x>0)
        {
            score1+=x;
            v1.pb(x);
        }
        else
        {
            x=abs(x);
            score2+=x;
            v2.pb(x);
        }
    }


    // dbg_vec(s1);
    // dbg_vec(s2);
    // dbg(score1);
    // dbg(score2);
    // dbg(last);
    if(score1 > score2) cout<<"first"<<endl;
    else if(score1 < score2) cout<<"second"<<endl;
    else
    {
        int i=0;
        bool flag=true;
        while(i<v1.size() && i<v2.size())
        {
            if(v1[i]>v2[i]) 
            {
                flag=false;
                cout<<"first"<<endl;
                return;
            }
            else if(v2[i]>v1[i])
            {
                flag=false;
                cout<<"second"<<endl;
                return;
            }
            i++;
        }
        if(flag)
        {
            if(last>0) cout<<"first"<<endl;
            else cout<<"second"<<endl;
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
    // cin >> t;
    while (t--) solve();
    return 0;
}