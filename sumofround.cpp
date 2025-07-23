#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int count = 0;
        vector<long long> ans;

        while (n)
        {
            if (n % 10 != 0)
                count++;
            ans.push_back(n % 10);
            n /= 10;
        }

        cout << count << endl;
        int m = 1;
        for (int i = 0; i < ans.size(); i++)
        {
            long long num = ans[i];
            num = (num * m);
            m *= 10;
            if (num != 0)
                cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}