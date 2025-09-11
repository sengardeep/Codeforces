#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>

void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> adj[n + 1];
   for (int i = 2; i <= n; i++)
   {
      int x;
      cin >> x;
      adj[i].push_back(x);
      adj[x].push_back(i);
   }
   // Find the kth parent
   vector<vector<int>> parent(n + 1, vector<int>(20, 0));
   function<void(int, int)> dfs = [&](int node, int par) -> void
   {
      parent[node][0] = par;

      // PreProcessing
      for (int i = 1; i <= 19; i++)
      {
         parent[node][i] = parent[parent[node][i - 1]][i - 1]; // If not exist then 0(Garbage)
      }
      for (auto child : adj[node])
      {
         if (child == par)
            continue;
         dfs(child, node);
      }
      return;
   };
   dfs(1, 0);
   while (q--)
   {
      int node, k;
      cin >> node >> k;
      // Go for every set bit and find ans
      int cnt = 0;
      while (k)
      {
         if (k & 1)
         {
            node = parent[node][cnt];
         }
         k >>= 1;
         cnt++;
      }
      if(node==0) node=-1;
      cout << node << endl;
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
   // cin >> t;
   while (t--)
   {
      solve();
   }

   return 0;
}
