#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long ans1 = -1, ans2 = -1;
        if (c > a)
            ans1 = 1;
        if ((a * b) > c)
            ans2 = b;

        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}