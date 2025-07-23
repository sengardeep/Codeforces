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
        int a, b, n;
        cin >> a >> b >> n;
        if (n % a == b)
        {
            cout << n << endl;
            continue;
        }
        else if (n % a < b)
        {
            cout << (n - (n % a) - (a - b)) << endl;
            continue;
        }
        else
        {
            cout << (n - (n % a) + b) << endl;
        }
    }
    return 0;
}