#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    int x = 1;
    for (int i = n; i > 1; i--)
    {
        ans += (x * (i - 1));
        x++;
    }
    ans += n;

    cout << ans << endl;

    return 0;
}