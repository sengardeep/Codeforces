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
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        int count = 0;
        for (int i = 2; i <= n / 2; i++)
        {
            if (v[i] == v[i - 1] || v[n - i + 1] == v[n - i + 2])
            {
                swap(v[i], v[n - i + 1]);
            }
        }

        for (int i = 1; i < n ; i++)
        {
            if (v[i] == v[i + 1])
                count++;
        }

        cout << count << endl;
    }
    return 0;
}