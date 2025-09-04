#include <bits/stdc++.h>
#define int long long
using namespace std;

void build(vector<vector<int>> a, vector<vector<vector<int>>> &lookup, int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
    {

        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {

            for (int k = 0; k < 5; k++)
                lookup[i][j][k] = max(lookup[i][j - 1][k], lookup[i + (1 << (j - 1))][j - 1][k]);
        }
    }
}

vector<int> query(int L, int R, vector<vector<vector<int>>> &lookup)
{
    int j = (int)log2(R - L + 1);

    vector<int> temp(5);

    for (int i = 0; i < 5; i++)
        temp[i] = max(lookup[L][j][i], lookup[R - (1 << j) + 1][j][i]);

    return temp;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> a(n, vector<long long>(5, 0));
    vector<vector<vector<long long>>> sparse(n, vector<vector<long long>>(20, vector<long long>(5, 0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    build(a, sparse, n);

    vector<int> answer(5, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i, right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            vector<int> mx = query(i, mid, sparse);
            int sum = accumulate(mx.begin(), mx.end(), 0ll);

            if (sum <= k)
            {
                if (ans < (mid - i + 1))
                {
                    ans = mid - i + 1;
                    answer = mx;
                }
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
    }

    for (int i = 0; i < m; i++)
        cout << answer[i] << " ";
}