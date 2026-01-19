#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Macros
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define frd(i, a, b) for (int i = a; i >= b; --i)
#define trav(a, x) for (auto& a : x)
#define endl '\n'

// Constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const double EPS = 1e-9;
const double PI = acos(-1);

// Debugging utility
#ifdef LOCAL
    #define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define dbg(x)
#endif

void _print(int x) { cerr << x; }
// void _print(ll x) { cerr << x; }
void _print(ull x) { cerr << x; }
void _print(ld x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(const string &x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void _print(const pair<T, V> &x) { cerr << "{"; _print(x.first); cerr << ", "; _print(x.second); cerr << "}"; }

template <typename T>
void _print(const vector<T> &v) { cerr << "["; for (size_t i = 0; i < v.size(); ++i) { _print(v[i]); if (i != v.size() - 1) cerr << ", "; } cerr << "]"; }

template <typename T>
void _print(const set<T> &s) { cerr << "{"; for (auto it = s.begin(); it != s.end(); ++it) { _print(*it); if (next(it) != s.end()) cerr << ", "; } cerr << "}"; }

template <typename T, typename V>
void _print(const map<T, V> &m) { cerr << "{"; for (auto it = m.begin(); it != m.end(); ++it) { _print(it->first); cerr << ": "; _print(it->second); if (next(it) != m.end()) cerr << ", "; } cerr << "}"; }

vector<int> sieve(int limit) { vector<bool> is_prime(limit + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= limit; ++i) { if (is_prime[i]) { for (int j = i * i; j <= limit; j += i)  is_prime[j] = false; } } vector<int> primes; for (int i = 2; i <= limit; ++i) {  if (is_prime[i]) primes.push_back(i);} return primes; }

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}



// Fast Input
template <typename T>
void read(T &x) { cin >> x; }

template <typename T, typename... Args>
void read(T &first, Args &...rest) {
    cin >> first;
    read(rest...);
}

template <typename T>
void read(vector<T> &v) {
    for (auto &x : v)
        cin >> x;
}

// Fast Output
template <typename T>
void print(const T &x) {
    cout << x << '\n';
}

template <typename T>
void print(const vector<T> &v) {
    for (const auto &x : v)
        cout << x << ' ';
    cout << '\n';
}



void solve(){
    int n, m, h;
    read(n, m, h);

    vector<int> orig(n);
    read(orig);

    unordered_map<int, int> diff;

    fr(i,0,m){
        int x,y;
        read(x,y);
        x--;

        diff[x] += y;

        if(orig[x] + diff[x] > h){
            diff.clear();
        }
    }

    vector<int> ans = orig;
    for(auto &p : diff){
        ans[p.first] += p.second;
    }

    print(ans);
}


signed main() {
    FAST_IO;
    // Your code here
    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
