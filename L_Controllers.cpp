#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int p = count(all(s), '+'), m = n - p;
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (p == m)
        {
            cout << "YES" << endl;
            continue;
        }
        if (a == b)
        {
            cout << "NO" << endl;
            continue;
        }
        int l = lcm(a, b);
        int x = (l / a), y = (l / b);
        if ((abs(p - m)) % (abs(x - y)) == 0)
        {
            int z = abs(p - m) / abs(y - x); // z = |k|
            // Minimal total button uses to realize (u,v) is |u| + |v| = (x + y) * p. Must not exceed n.
            if ((x + y) * z > n)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}