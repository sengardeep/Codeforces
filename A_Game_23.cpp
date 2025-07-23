#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    // if (n == m)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    int x = m / n;
    int ans = 0;
    while (x > 0 && x % 6 == 0)
    {
        ans += 2;
        x /= 6;
    }
    while (x > 0 && x % 2 == 0)
    {
        ans++;
        x /= 2;
    }

    while (x > 0 && x % 3 == 0)
    {
        ans++;
        x /= 3;
    }
    if (x != 1)
        ans = -1;
    cout << ans << endl;
    return 0;
}