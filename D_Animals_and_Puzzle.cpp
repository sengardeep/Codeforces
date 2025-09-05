#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

const int MAXN = 1000;
const int MAXLOG = 11; // since log2(1000) ~ 10
int st[MAXN][MAXN][MAXLOG][MAXLOG];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    auto f = [](int n)
    {
        int ans = 0;
        while (1 << (ans + 1) <= n)
            ans++;
        return ans;
    };
    int LOG1 = f(n), LOG2 = f(m);
    // vector<vector<vector<vector<int>>>> st(n, vector<vector<vector<int>>>(m, vector<vector<int>>(LOG1 + 1, vector<int>(LOG2 + 1))));

    // st[x][y][k][l]=answer for rectangle with top-left corner (x, y), height 2^k, width 2^l
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (i > 0 && j > 0 && v[i][j] != 0)
            {
                v[i][j] = min({v[i - 1][j], v[i][j - 1], v[i - 1][j - 1]}) + 1;
            }
            st[i][j][0][0] = v[i][j];
        }
    }
    // along width
    for (int l = 1; l <= LOG2; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + (1 << l) <= m; j++) {
                st[i][j][0][l] = max(st[i][j][0][l - 1],
                                     st[i][j + (1 << (l - 1))][0][l - 1]);
            }
        }
    }

    // along height
    for (int k = 1; k <= LOG1; k++) {
        for (int l = 0; l <= LOG2; l++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                for (int j = 0; j + (1 << l) <= m; j++) {
                    st[i][j][k][l] = max(st[i][j][k - 1][l],
                                         st[i + (1 << (k - 1))][j][k - 1][l]);
                }
            }
        }
    }

    auto query = [&](int r1, int c1, int r2, int c2) {
        int k = f(r2 - r1 + 1);
        int l = f(c2 - c1 + 1);
        int m1 = max(st[r1][c1][k][l], st[r2 - (1 << k) + 1][c1][k][l]);
        int m2 = max(st[r1][c2 - (1 << l) + 1][k][l],
                     st[r2 - (1 << k) + 1][c2 - (1 << l) + 1][k][l]);
        return max(m1, m2);
    };
    int q;
    cin >> q;
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1;
        --r2;
        --c1;
        --c2;
        //We must see if there’s some cell (x,y) in (r1+mid-1..r2, c1+mid-1..c2) such that dp[x][y] ≥ mid.
        int lo = 1, hi = min(r2-r1+1, c2-c1+1), ans = 0;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int rr1 = r1 + mid - 1;
            int cc1 = c1 + mid - 1;
            if(rr1 > r2 || cc1 > c2){
                hi = mid - 1;
                continue;
            }
            int mx = query(rr1, cc1, r2, c2);
            if(mx >= mid){
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        cout<<ans<<endl;
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
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
