#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int target = abs(a - b);
        int ans = (target % 10 == 0) ? target / 10 : target / 10 + 1;
        cout << ans << endl;
    }
    return 0;
}