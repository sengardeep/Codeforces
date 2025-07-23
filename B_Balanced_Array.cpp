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
        int n;
        cin >> n;
        if ((n / 2) & 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            vector<int> ans(n);
            int num = 2;
            int flag = 0;
            for (int i = 0; i < n / 2; i++)
            {
                ans[i] = num;
                num += 2;
                if (flag < n/4)
                {
                    ans[i + n / 2] = ans[i] - 1;
                    flag+=1;
                }
                else
                {
                    ans[i + n / 2] = ans[i] + 1;
                }
            }

            for (auto it : ans)
                cout << it << " ";

            cout << endl;
        }
    }
    return 0;
}