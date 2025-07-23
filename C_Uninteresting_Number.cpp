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

        vector<int> num(s.size());
        int sum = 0, two = 0, three = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num[i] = (s[i] - '0');
        }

        for (auto it : num)
        {
            int n = it;
            sum += (n);
            if (n == 2)
                two++;
            if (n == 3)
                three++;
        }

        int target = (-sum) % 9;
        if (target < 0)
            target += 9;
        bool flag = false;
        for (int i = 0; i <= 2 && i <= three; i++)
        {
            int t = target - 6 * i;
            int rem = (5 * t) % 9;
            if (rem < 0)
                rem += 9;
            if (rem <= two)
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}