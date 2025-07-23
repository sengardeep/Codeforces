#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    int size = 1;
    vector<int> ans;
    vector<bool> freq(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        st.insert(a[i]);
        freq[a[i]] = true;
        if (st.size() == size)
        {
            ans.push_back(a[i]);
            size++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == false)
            ans.push_back(i);
    }

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
