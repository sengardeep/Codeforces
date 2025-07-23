#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum+=arr[i];
        }
        
        int low = min(sum - x, sum - y), high = max(sum - y, sum - x);
        // cout<<"low"<<low<<endl;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int start = i + 1, end = n - 1;
            int el = arr[i];
            int first = 0, last = 0;
            if (el > high)
                break;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (el + arr[mid] >= low)
                {
                    first = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            start = i + 1;
            end = n - 1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (el + arr[mid] <= high)
                {
                    last = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            if(first <= last && first!=0)
            ans += (last - first + 1);
        }
        cout << ans << endl;
    }
    return 0;
}