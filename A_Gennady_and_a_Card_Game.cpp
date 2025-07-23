#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool flag = false;
    int n = 5;
    while (n--)
    {
        string temp;
        cin >> temp;
        if (temp[0] == s[0] || temp[1] == s[1])
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}