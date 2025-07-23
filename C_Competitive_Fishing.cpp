#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> results;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> temp;
        int count = 0;

        for (int p = n - 1; p >= 0; --p)
        {
            temp.push_back(count) ;
            if (s[p] == '1') count++;
            else count -= 1;
        }

        sort(temp.rbegin(), temp.rend());

        int temp2 = 0, result = -1;

        for (int i = 2; i <= n; ++i)
        {
            if (i - 2 < temp.size())
            {
                temp2 += temp[i - 2];

                if (temp2 >= k)
                {
                    result = i;
                    break;
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}