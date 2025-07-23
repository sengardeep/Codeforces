#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int f(const map<int, int> &freq)
{
    int mex = 0;
    while (freq.find(mex) != freq.end())
    {
        mex++;
    }
    return mex;
}
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        vector<int> a(n, -1);

        for (int i = 0; i < n; i++)
        {
            map<int, int> freq;
            freq[a[(i - 1 + n) % n]]++;
            freq[a[(i + 1) % n]]++;

            if (i == x)
            {
                freq[a[y]]++;
            }
            if (i == y)
            {
                freq[a[x]]++;
            }

            a[i] = f(freq);
        }

        for (int value : a)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}