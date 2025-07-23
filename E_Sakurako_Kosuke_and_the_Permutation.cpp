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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<bool> a(n + 1, 0);
        long long res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                int count = 0, j = i;

                while (a[j] == 0)
                {
                    a[j] = true;
                    j = v[j - 1];
                    count++;
                }

                if (count >= 3)
                    res += (count - 1) / 2;
            }
        }

        cout << res << endl;
    }
    return 0;
}