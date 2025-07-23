#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define MAX_VAL 400005
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;

    vector<int> value_count(MAX_VAL, 0);

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> l(n), r(n);

        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }

        vector<int> fix;
        vector<int> count;

        for (int i = 0; i < n; i++)
        {
            if (l[i] == r[i])
            {
                int value = l[i];
                auto it = find(fix.begin(), fix.end(), value);
                if (it != fix.end())
                {
                    int idx = it - fix.begin();
                    count[idx]++;
                }
                else
                {
                    fix.push_back(value);
                    count.push_back(1);
                }
            }
        }

        vector<int> unique;
        unique.reserve(fix.size());
        for (size_t i = 0; i < fix.size(); ++i)
        {
            unique.push_back(fix[i]);
            value_count[fix[i]] += count[i];
        }

        sort(unique.begin(), unique.end());
        string result = "";
        result.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int left = l[i];
            int right = r[i];
            if (left < right)
            {
                int lower_idx = lower_bound(unique.begin(), unique.end(), left) - unique.begin();
                int upper_idx = upper_bound(unique.begin(), unique.end(), right) - unique.begin();
                int res = upper_idx - lower_idx;
                int segment_size = right - left + 1;
                if (res < segment_size)
                    result += '1';
                else
                    result += '0';
            }
            else
            {
                int value = left;
                if (value_count[value] <= 1)
                    result += '1';
                else
                    result += '0';
            }
        }

        cout << result << "\n";

        for (size_t i = 0; i < fix.size(); ++i)
        {
            value_count[fix[i]] -= count[i];
        }
    }
    return 0;
}