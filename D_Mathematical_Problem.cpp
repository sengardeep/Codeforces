/*
██████╗░░█████╗░██████╗░███╗░░░███╗░█████╗░░██████╗██╗░░██╗██╗   ░██████╗██╗░░██╗██╗░░░██╗██████╗░██╗░░░██╗
██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔════╝██║░░██║██║   ██╔════╝██║░░██║██║░░░██║██╔══██╗██║░░░██║
██████╦╝███████║██║░░██║██╔████╔██║██║░░██║╚█████╗░███████║██║   ╚█████╗░███████║██║░░░██║██████╔╝██║░░░██║
██╔══██╗██╔══██║██║░░██║██║╚██╔╝██║██║░░██║░╚═══██╗██╔══██║██║   ░╚═══██╗██╔══██║██║░░░██║██╔══██╗██║░░░██║
██████╦╝██║░░██║██████╔╝██║░╚═╝░██║╚█████╔╝██████╔╝██║░░██║██║   ██████╔╝██║░░██║╚██████╔╝██║░░██║╚██████╔╝
╚═════╝░╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝   ╚═════╝░╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝░╚═════╝░
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #define int long long
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
#define MAX 100000
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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
// Date : 21-06-2025 
// Time : 09:50


// Solution Function
void solve() {
    int n;
    read(n);
    string s;
    read(s);
    if(n<=2)
    {
        cout<<stoi(s)<<endl;
        return;
    }
    bool zero=false;
    for(auto it : s) if(it=='0') zero=true;
    if(zero)
    {
        if(n==3 && (s[0]=='0' || s[n-1]=='0')) 
        {
            cout<<0<<endl;
            return;
        }
        else if(n>3) 
        {
            cout<<0<<endl;
            return;
        }
    }
    int mini = INT_MAX;
    string min_str=to_string(mini);
    FOR(i, 0, n - 1)
    {
        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
        string temp=to_string(num);
        min_str=to_string(mini);
        if(temp.size()==1) temp = "0" + temp;
        if(min_str.size()==1) min_str = "0" + min_str;
        // dbg(min_str);
        // dbg(temp);
        if(mini != INT_MAX && temp[0]==min_str[0] && mini%10 == 1) mini=max(mini,num);
        if(mini != INT_MAX && temp[0]==min_str[0] && num%10 == 1) continue;
        else mini = min(mini, num);
    }
    // dbg(mini);
    size_t pos = s.find(to_string(mini));
    if (pos != string::npos) {
        s.erase(pos, 2);
    }

    int sum = 0;
    for (char c : s)
    {
        if(c=='1') continue;
        sum += c - '0';
    }

    if(mini!=1) sum+=mini;
    if(sum==0) sum+=1;
    cout << sum << endl;

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
/*
██████╗░░█████╗░██████╗░███╗░░░███╗░█████╗░░██████╗██╗░░██╗██╗   ██╗░░██╗██╗░░██╗░█████╗░████████╗░█████╗░███╗░░░███╗
██╔══██╗██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔════╝██║░░██║██║   ██║░██╔╝██║░░██║██╔══██╗╚══██╔══╝██╔══██╗████╗░████║
██████╦╝███████║██║░░██║██╔████╔██║██║░░██║╚█████╗░███████║██║   █████═╝░███████║███████║░░░██║░░░███████║██╔████╔██║
██╔══██╗██╔══██║██║░░██║██║╚██╔╝██║██║░░██║░╚═══██╗██╔══██║██║   ██╔═██╗░██╔══██║██╔══██║░░░██║░░░██╔══██║██║╚██╔╝██║
██████╦╝██║░░██║██████╔╝██║░╚═╝░██║╚█████╔╝██████╔╝██║░░██║██║   ██║░╚██╗██║░░██║██║░░██║░░░██║░░░██║░░██║██║░╚═╝░██║
╚═════╝░╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝   ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝
*/