#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), u(n, vector<int>(m, 1));
    vector<int> r(n, 1), c(m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 0)
            {
                r[i] = 0;
                c[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1 && (r[i] == 0 && c[j] == 0))
            {
                cout << "NO";
                return 0;
            }
        }
    }

    int r1 = count(r.begin(), r.end(), 1);
    int c1 = count(c.begin(), c.end(), 1);

    if ((c1 == 0 && r1 != 0) || (c1 != 0 && r1 == 0))
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << (r[i] & c[j]) << " ";
        cout << endl;
    }
    return 0;
}