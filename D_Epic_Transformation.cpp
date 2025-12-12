#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];
   map<int, int> map;
   for (auto x : v)
      map[x]++;
   int mx = 0, sum = 0;
   for (auto [x, f] : map){
      mx = max(mx, f);
      sum += f;
   }
   if (mx > n - mx)
   {
      cout << (2 * mx - n) << endl;
      return;
   }
   else
   {
      if (sum % 2)
         cout << 1 << endl;
      else
         cout << 0 << endl;
      return;
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
