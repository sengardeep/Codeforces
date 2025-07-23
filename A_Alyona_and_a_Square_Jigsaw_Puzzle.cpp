#include <bits/stdc++.h>
#define MOD 1000000007
// #define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
bool isPerfectSquare(long long num)
{
    if (num < 0)
        return false;
    long long sqrtNum = static_cast<long long>(sqrt(num));
    return sqrtNum * sqrtNum == num;
}

vector<int> enterArr(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int main()
{
    fastread();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr = enterArr(n);
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (isPerfectSquare(sum))
            {
                long long p = static_cast<long long>(sqrt(sum));
                if (p % 2 == 1)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}