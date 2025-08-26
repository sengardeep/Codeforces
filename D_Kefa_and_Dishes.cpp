#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#define F first
#define S second
#define P system("PAUSE");
#define H return 0;
#define pb push_back
using namespace std;
const long long A = 100000000000000LL, N = 1228228;

long long mask, i, j, n, m, k, a[N], b[N], x, y, z, c[21][21], o, ot, dp[N][21];

long long len(long long mask)
{
    long long k = 0;
    for (i = 0; i < n; i++)
        if (mask & b[i])
            k++;
    return k;
}

int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    b[0] = 1;
    for (i = 1; i <= n; i++)
        b[i] = b[i - 1] * 2;
    while (k--)
        scanf("%d%d%d", &x, &y, &z), c[x - 1][y - 1] = z;
    for (i = 0; i < n; i++)
        dp[b[i]][i] = a[i];
    for (mask = 0; mask < b[n]; mask++)
        for (i = 0; i < n; i++)
            if (mask & b[i])
            {
                for (j = 0; j < n; j++)
                    if ((mask & b[j]) == 0)
                        dp[(mask | b[j])][j] = max(dp[(mask | b[j])][j], dp[mask][i] + c[i][j] + a[j]);
            }
    for (mask = 0; mask < b[n]; mask++)
        if (len(mask) == m)
            for (i = 0; i < n; i++)
                o = max(o, dp[mask][i]);
    cout << o << "\n";
}