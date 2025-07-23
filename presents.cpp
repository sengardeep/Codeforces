#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i + 1;
    }

    for (auto it : mp)
        cout << it.second << " ";
    return 0;
}