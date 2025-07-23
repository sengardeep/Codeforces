#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
void solve()
{
    int d, n;
    cin >> n >> d;
    vector<int> ans;
    ans.push_back(1);
    if (d % 3 == 0 || n >= 3)
    {
        ans.push_back(3);
    }
    if (d % 5 == 0)
    {
        ans.push_back(5);
    }
    if (d % 7 == 0 || n >= 3)
    {
        ans.push_back(7);
    }
    if (d % 9 == 0 || (d % 3 == 0 && n >= 3) || n >= 6)
    {
        ans.push_back(9);
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}