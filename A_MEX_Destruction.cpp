#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int cases;
    cin >> cases;
    while (cases--)
    {
        int size;
        cin >> size;
        vector<int> nums(size);
        for (int i = 0; i < size; i++)
        {
            cin >> nums[i];
        }
        int zeros = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
                zeros++;
        }
        if (zeros == size)
        {
            cout << "0" << endl;
            continue;
        }
        int status = -1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != 0 && status == -1)
                status = 0;
            else if (status == 0 && nums[i] == 0)
                status = 1;
            else if (status == 1 && nums[i] != 0)
                status = 2;
        }
        if (status == 2)
            cout << "2" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}
