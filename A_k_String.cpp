#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    map<char, int> mp;
    string s;
    cin >> s;
    for (auto it : s)
        mp[it]++;
    for (auto it : mp)
    {
        if (it.second < k || it.second % k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    string ans = "";
    for (auto it : mp)
    {
        int freq = (it.second / k);
        while (freq--)
            ans += it.first;
    }
    string res = "";
    while (k--)
        res += ans;
    cout << res << endl;
    return 0;
}