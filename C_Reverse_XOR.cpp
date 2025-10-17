#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    if (n == 0){
        cout << "YES" << endl;
        return;
    }
    int copy = n;
    while ((copy & 1LL) == 0) copy >>= 1;
    int temp = copy;
    int len = 0;
    while (temp){
        len++;
        temp >>= 1;
    }
    // palindrome
    bool flag = true;
    int j = len-1;
    for (int i = 0; i < j; i++){
        if (((copy >> i) & 1LL) != ((copy >> j) & 1LL))
        {
            flag = false;
            break;
        }
        j--;
    }
    if (!flag){
        cout << "NO" << endl;
        return;
    }
    if ((len & 1) && ((copy >> (len / 2)) & 1LL)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
