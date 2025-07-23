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
// Date : 06-06-2025 
// Time : 17:37


// Solution Function
void solve() {
    int n;
    read(n);
    string s;
    read(s);

    vi even(26,0),odd(26,0);
    int maxEven=INT_MIN,maxOdd=INT_MIN;

    FOR(i,0,n) 
    {
        if(i&1) 
        {
            odd[s[i]-'a']++;
            maxOdd=max(maxOdd,odd[s[i]-'a']);
        }
        else
        {
            even[s[i]-'a']++;
            maxEven=max(maxEven,even[s[i]-'a']);
        }
    }
    if(n%2==0)
    {
        int ans = (((n+1)/2)-maxEven) + ((n/2)-maxOdd);
        cout<<ans<<endl;
    }
    else
    {
        vi even1(26,0),odd1(26,0);
        int ans = 1e6;
        int x=n-1;
        FOR(i,0,n)
        {
            maxEven=INT_MIN,maxOdd=INT_MIN;
            if(i&1)  odd[s[i]-'a']--;
            else even[s[i]-'a']--;

            if(i>0)
            {
                if((i-1)%2==0) even1[s[i-1]-'a']++;
                else odd1[s[i-1]-'a']++;
            }
            FOR(j,0,26)
            {
                maxEven=max(maxEven,even1[j]+odd[j]);
                maxOdd=max(maxOdd,odd1[j]+even[j]);
            }
            ans=min(ans,(((x+1)/2)-maxEven) + ((x/2)-maxOdd));
        }
        // dbg(maxEven);
        // dbg(maxOdd);

        cout<<(ans+1)<<endl;
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