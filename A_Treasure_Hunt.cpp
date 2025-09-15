#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
const int INF = 1e18;

void solve()
{
    int h, w, k;
    cin >> h >> w >> k;
    int n = h * w;
    vector<int> moves(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    auto flat = [&](int r, int c)
    {
        return r * w + c;
    };
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int v = flat(x, y);
        if (moves[v] > 0)
        {
            moves[v] = 0;
            pq.push({0, v});
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> min1(n, INF), min2(n, INF);
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist != moves[node])
            continue;
        int r = node / w, c = node % w;
        for (int i = 0; i < 4; ++i)
        {
            int row = r + dir[i].first, col = c + dir[i].second;
            if (row < 0 || row >= h || col < 0 || col >= w)
                continue;
            int v = flat(row, col);
            int val = moves[node];
            if (val < min1[v])
            {
                min2[v] = min1[v];
                min1[v] = val;
            }
            else if (val < min2[v])
            {
                min2[v] = val;
            }
            else
                continue;

            if (min2[v] < INF)
            {
                int temp = 1 + min2[v];
                if (temp < moves[v])
                {
                    moves[v] = temp;
                    pq.push({moves[v], v});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (moves[i] < INF)
            ans += moves[i];
    cout << ans << endl;
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
