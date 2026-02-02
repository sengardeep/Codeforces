#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
   int n, q;
   cin >> n >> q;
   string s;
   cin >> s;

   vector<int> lf(n), rg(n);

   int last_zero = -1;
   for (int i = 0; i < n; i++)
   {
      if (s[i] == '0')
      {
         last_zero = i;
      }
      lf[i] = last_zero;
   }

   int first_one = n;
   for (int i = n - 1; i >= 0; i--)
   {
      if (s[i] == '1')
      {
         first_one = i;
      }
      rg[i] = first_one;
   }

   set<pii> set;

   for (int i = 0; i < q; i++)
   {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      int start_change = rg[l];
      int end_change = lf[r];

      if (start_change > end_change)
      {
         set.insert({-1, -1});
      }
      else
      {
         set.insert({start_change, end_change});
      }
   }

   cout << set.size() << endl;
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
