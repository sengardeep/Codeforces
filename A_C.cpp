#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (a > b)
            swap(a, b);
        int ans = 0;
        while (a <= n && b <= n)
        {
            a += b;
            swap(a, b);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}