#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'T')
            ans += 4;
        else if (s[0] == 'C')
            ans += 6;
        else if (s[0] == 'O')
            ans += 8;
        else if (s[0] == 'D')
            ans += 12;
        else
            ans += 20;
    }
    cout << ans << endl;
    return 0;
}