#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        vector<int> v(s.size());
        for (int i=0;i<s.size();i++)
            v[i]=(s[i] - '0');

        for (int i = 1; i < s.size(); i++)
        {
            while (i >= 1 && v[i] > v[i - 1] + 1 && v[i] > 0)
            {
                int temp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = temp - 1;
            

            if (i > 1)
                i--;
            else
                break;
            }
        }

        string temp="";
        for (auto it : v)
            temp += to_string(it);

        cout << temp << endl;
    }
    return 0;
}