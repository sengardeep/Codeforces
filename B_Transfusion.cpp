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
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if (sum % n != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        int target = (sum + 1) / n;

        int even = 0, odd = 0;
        int countEven=0,countOdd=0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {

                odd += v[i];
                countOdd++;
            }
            else
            {
                even += v[i];
                countEven++;
            }
        }

        if (even == target * countEven &&  odd == target * countOdd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}