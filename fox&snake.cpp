#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;

    string s1 = "";
    string s2 = "";

    int j = col;
    while (j--)
        s1 += '#';
    j = col;
    while (--j)
        s2 += '.';

    s2 += '#';

    vector<string> ans;
    for (int i = 0; i < row; i++)
    {
        if (i & 1)
            ans.push_back(s2);
        else
            ans.push_back(s1);
    }

    for (int i = 3; i < ans.size(); i += 4)
    {
        reverse(ans[i].begin(), ans[i].end());
    }

    for (auto it : ans)
        cout << it << endl;
    return 0;
}