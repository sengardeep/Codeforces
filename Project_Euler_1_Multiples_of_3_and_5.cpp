#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
                ans += i;
        }
        cout << ans << endl;
    }
    return 0;
}