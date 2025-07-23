#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    bool flag = true;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] <= 90)
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        if (s[0] > 90)
            s[0] -= 32;
        else
            s[0] += 32;
        for (int i = 1; i < s.size(); i++)
            s[i] += 32;
    }
    cout << s << endl;
    return 0;
}