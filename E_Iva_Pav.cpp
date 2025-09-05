#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

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
        int n;
        cin >> n;
        vector<int> v(n);
        auto f = [](int n)
        {
            int ans = 0;
            while ((1 << (ans + 1)) <= n)
                ans++;
            return ans;
        };
        int LOG = f(n);
        vector<vector<int>> st(n, vector<int>(LOG + 1));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            st[i][0] = v[i];
        }

        // Preprocessing
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];

        function<int(int, int)> query = [&](int l, int r) -> int
        {
            int len = r - l + 1;
            int k = f(len);
            return st[l][k] & st[r - (1 << k) + 1][k];
        };

        int q;
        cin>>q;
        while(q--){
            int l,k;
            cin>>l>>k;
            --l;
            int r=-2;
            int start=l,end=n-1;
            while(start<=end){
                int mid=(start+end)/2;

                if(query(l,mid) >= k){
                    r=mid;
                    start=mid+1;
                }
                else end=mid-1;
            }

            cout<<r+1<<" ";
        }
        cout<<endl;
    }

    return 0;
}
