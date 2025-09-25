#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

map<int, int> parent;
int findPar(int x)
{
   if (parent.find(x) == parent.end())
      return x;
   return parent[x] = findPar(parent[x]);
}
void unite(int x, int y)
{
   int px = findPar(x);
   int py = findPar(y);
   if (px != py)
   {
      parent[px] = py;
   }
}
void solve()
{
   parent.clear();
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   set<int> st;
   for (int i = 0; i < m; i++)
   {
      int x;
      cin >> x;
      st.insert(x);
   }
   for (auto x : st) unite(x, x + 1);
   vector<int> path(n + 1);
   path[0] = 1;
   for (int i = 1; i <= n; ++i)
   {
      if (i > 1 && s[i - 2] == 'B')
         path[i - 1] = findPar(path[i - 2] + 1);
      int pos;
      if (s[i - 1] == 'A') pos = path[i - 1] + 1;
      else pos = findPar(path[i - 1] + 1);
      path[i] = pos;
      if (st.find(pos) == st.end())
      {
         st.insert(pos);
         unite(pos, pos + 1);
      }
   }
   cout << st.size() << endl;
   for (auto x : st) cout<<x<<" ";
   cout << endl;
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
