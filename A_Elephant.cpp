#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int n;
    cin >> n;
    if (n % 5 == 0)
        cout << n / 5 << endl;
    else
        cout << (n / 5) + 1 << endl;
    return 0;
}