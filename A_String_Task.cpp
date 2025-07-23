#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<char> st = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (int i = 0; i < s.size(); i++)
    {
        if (st.find(s[i]) != st.end())
            s[i] = '*';
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= 90 && s[i] != '*')
            s[i] += 32;
    }
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            ans += ".";
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}