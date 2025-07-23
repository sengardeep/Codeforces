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
        int n, m;
        cin >> n >> m;
        if (n == 1)
            cout << 0 << endl;
        else if (n == 2)
            cout << m << endl;
        else 
            cout << m * 2 << endl;
        
    }
    return 0;
}