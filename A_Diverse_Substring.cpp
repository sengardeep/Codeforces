#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cout << "YES" << endl;
            string temp = "";
            temp+=s[i];
            temp+=s[i+1];
            cout << temp << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}