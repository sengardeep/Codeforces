#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (i * (i + 1)) / 2;
        if (ans > n)
        {
            ans = i-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}