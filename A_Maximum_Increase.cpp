#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = INT_MIN;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
        }
        else
        {
            ans = max(count, ans);
            count = 1;
        }
    }
    ans = max(count, ans);
    cout << ans << endl;
    return 0;
}