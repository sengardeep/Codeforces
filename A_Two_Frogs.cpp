#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;


//MARCO's
#define vi vector<int>
#define vc vector<char>
#define read(v, n) for (int i = 0; i < n; i++) cin >> v[i];
#define print(v) for (auto &x : v) cout << x << " "; cout << endl;
#define all(v) v.begin(), v.end()
#define pb push_back
#define LOOP(arr) for (auto &it : arr)
#define FOR(i,start, n) for(int i = start; i < n; i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Alice cout << "Alice" << endl;
#define Bob cout << "Bob" << endl;
#define First cout << "First" << endl;
#define Second cout << "Second" << endl;

// Debugging macro
#define dbg(x...) cerr << "[" << #x << "] = ["; debug_out(x)
void debug_out() { cerr << "]" << endl; }
template <typename T, typename... Args>
void debug_out(T x, Args... args) {
    cerr << x;
    if (sizeof...(args)) cerr << ", ";
    debug_out(args...);
}

// Utility functions
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int mod_exp(int base, int exp, int mod = MOD) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int binary_search(const vi &v, int target) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == target) return mid; // Found
        else if (v[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

// Created by Deepraj Singh (Deep)

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int diff=abs(a-b);
    if(diff&1) NO
    else YES
}
int32_t main()
{
    fastread();
    int t = 1;
    cin >> t; // Comment if there is one test case
    while (t--) {
        solve();
    }
    return 0;
}