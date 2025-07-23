#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int m, n;
    cin >> m >> n;
    if (n % 2 == 0)
    {
        cout << (m * (n / 2)) << endl;
    }
    else
    {
        cout << (m * (n / 2)) + (m / 2) << endl;
    }

    return 0;
}