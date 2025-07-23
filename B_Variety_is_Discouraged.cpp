#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;

// Common Macros
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define FOR(i, start, end) for (int i = start; i < end; ++i)

// Fast Input/Output Functions
template <typename T>
void read(T &x) { cin >> x; }
template <typename T, typename... Args>
void read(T &first, Args &...rest)
{
    cin >> first;
    read(rest...);
}
template <typename T>
void read(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

// Solution Function
void solve()
{
    int n;
    read(n);
    vi a(n);
    read(a);

    unordered_map<int, int> freq;
    FOR(i, 0, n)
    freq[a[i]]++;

    vi unique(n, 0);
    FOR(i, 0, n)
    if (freq[a[i]] == 1) unique[i] = 1;

    int maxi = 0, start = -1, end = -1;
    int tempStart = 0, tempLen = 0;

    FOR(i, 0, n)
    {
        if (unique[i])
        {
            if (tempLen == 0)
                tempStart = i;
            tempLen++;
        }
        else
        {
            if (tempLen > maxi)
            {
                maxi = tempLen;
                start = tempStart;
                end = i - 1;
            }
            tempLen = 0;
        }
    }
    if (tempLen > maxi)
    {
        maxi = tempLen;
        start = tempStart;
        end = n - 1;
    }

    if (maxi == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << start + 1 << " " << end + 1 << endl;
    }
}

// Main Function
int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
