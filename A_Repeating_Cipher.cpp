#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    int j = 0;
    for (int i = 0; i < n; i += j)
    {
        ans += s[i];
        j++;
    }
    cout << ans << endl;
    return 0;
}