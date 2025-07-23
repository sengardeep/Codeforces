#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = INT_MIN;
    int passenger = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        passenger += b;
        passenger -= a;
        ans = max(ans, passenger);
    }

    cout << ans << endl;
    return 0;
}