#include <bits/stdc++.h>
#define MOD (const int)1e9 + 7
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int n;
    cin >> n;
    if (n & 1)
        cout << "Ehab" << endl;
    else
        cout << "Mahmoud" << endl;
    return 0;
}