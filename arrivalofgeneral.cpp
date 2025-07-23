#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maximum = INT_MIN, minimum = INT_MAX, maxIdx = 0, minIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
            maxIdx = i;
        }
        if (arr[i] <= minimum)
        {
            minimum = arr[i];
            minIdx = i;
        }
    }

    int ans = (maxIdx - 0) + (n - 1 - minIdx);
    ans = (maxIdx > minIdx) ? (ans - 1) : ans;

    cout << ans << endl;
    return 0;
}