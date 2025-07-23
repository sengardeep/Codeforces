#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int left = -1, right = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                right = n - i - 1;
                break;
            }
        }

        if (left == -1)
        {
            cout << n << endl;
        }
        else
        {
            cout << max(((2 * n) - (2 * left)), ((2 * n) - (2 * right))) << endl;
        }
    }
    return 0;
}