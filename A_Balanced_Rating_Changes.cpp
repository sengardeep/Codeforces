#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i] / 2;
    }

    int currSum = accumulate(b.begin(), b.end(), 0);
    int idx = 0;
    while (currSum != 0)
    {
        if (currSum > 0)
        {
            if (a[idx] % 2 != 0 && a[idx] < 0)
            {
                b[idx] -= 1;
                currSum -= 1;
            }
        }
        else if (currSum < 0)
        {
            if (a[idx] % 2 != 0 && a[idx] > 0)
            {
                b[idx] += 1;
                currSum += 1;
            }
        }
        idx++;
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << endl;
    return 0;
}