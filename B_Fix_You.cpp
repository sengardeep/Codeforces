#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<string> v(row);
        for (int i = 0; i < row; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < col; i++)
        {
            if (v[row - 1][i] == 'D')
                ans++;
        }
        for (int i = 0; i < row; i++)
        {
            if (v[i][col - 1] == 'R')
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}