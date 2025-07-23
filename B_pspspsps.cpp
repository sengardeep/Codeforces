#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
bool check(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    bool flag = true;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (arr[i - 1] < i)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string temp = " ";
        str = temp + str;

        deque<int> p1;
        vector<int> nxt1(n + 1, INT_MAX);
        for (int i = n; i >= 1; i--)
        {
            if (str[i] == 'p')
            {
                p1.push_front(i);
            }
            if (!p1.empty())
            {
                nxt1[i] = p1.front();
            }
        }

        deque<int> p2;
        vector<int> prv1(n + 1, INT_MAX);
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == 's')
            {
                p2.push_back(i);
            }
            if (!p2.empty())
            {
                prv1[i] = p2.front();
            }
        }

        vector<int> mini(n);
        for (int i = 1; i <= n; i++)
        {
            int dist_p = INT_MAX;
            if (nxt1[i] != INT_MAX)
            {
                dist_p = nxt1[i];
            }

            int dist_s = INT_MAX;
            if (prv1[i] != INT_MAX)
            {
                dist_s = n - prv1[i] + 1;
            }

            if (dist_p != INT_MAX && dist_s != INT_MAX)
            {
                mini[i - 1] = min(dist_p, dist_s);
            }
            else if (dist_p != INT_MAX)
            {
                mini[i - 1] = dist_p;
            }
            else if (dist_s != INT_MAX)
            {
                mini[i - 1] = dist_s;
            }
            else
            {
                mini[i - 1] = n;
            }
        }

        if (check(mini))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}