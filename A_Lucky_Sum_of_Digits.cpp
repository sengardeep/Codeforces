#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n;
    cin >> n;
    string ans ="";
    // bool flag1 = false;
    // bool flag2 = false;
    while (n % 7 != 0)
    {
        n -= 4;
        // flag1 = true;
        ans += "4";
    }

    while (n >= 7)
    {
        n -= 7;
        ans += "7";
        // flag2 = true;
    }
    if (n == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}