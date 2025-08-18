#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200;
int dp[N][N], a[N], n, x, k;

int f(int index, int left)
{
    if(index == n) return (left == 0 ? 0 : -1e12);
    if(left == 0)  return ((n - index) < k ? 0 : -1e12);
    
    int sum = -1e12;

    if(dp[index][left] != -1) return dp[index][left];

    for(int i = index; i < min(index + k, n); i++)
    {
        sum = max(sum, a[i] + f(i + 1, left - 1));
    }

    return dp[index][left] = sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> x;

    for(int i = 0; i < n; i++) cin >> a[i];

    if(n / k > x)
    {
        cout << -1 << "\n";
        return 0;
    }

    cout << f(0, x);
}