#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
vector<int> compute(vector<int> &arr)
{
    int n = arr.size();
    int mex = 0;
    map<int, int> freq;
    for (auto it : arr)
        freq[it]++;
    while (freq[mex])
        mex++;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] > 1)
        {
            ans[i] = mex;
        }
        else
        {
            if (arr[i] < mex)
            {
                ans[i] = arr[i];
            }
            else
            {
                ans[i] = mex;
            }
        }
    }
    return ans;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (k <= 5)
    {
        vector<int> temp;
        while(k--){
            temp = compute(v);
            v=temp;
        }
        int ans = accumulate(begin(temp), end(temp), 0LL);
        cout << ans << endl;
        return;
    }
    vector<int> prev = v, curr = v;
    while (k--)
    {
        vector<int> temp = compute(curr);
        // for (auto it : temp)
        //     cerr << it << " ";
        if (temp == prev)
        {
            if ((k+1) & 1)
            {
                int ans = accumulate(begin(prev), end(prev), 0LL);
                cout << ans << endl;
                return;
            }
            else
            {
                int ans = accumulate(begin(curr), end(curr), 0LL);
                cout << ans << endl;
                return;
            }
            // dbg(k);
        }
        prev = curr;
        curr = temp;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
