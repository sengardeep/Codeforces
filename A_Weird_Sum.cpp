#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

const int k =1e5+6;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

    // k is the maximum possible value (assuming values are 1 to n*m)
    // Group positions by value: same[val] holds list of (row, col) pairs for value 'val'
    vector<vector<pair<int, int>>> same(k + 1);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) same[v[i][j]].push_back({i, j});

    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        if (same[i].empty()) continue;
        vector<pair<int, int>> pos = same[i];
        // Compute sum of |ri - rj| for all pairs in this group (rows are already sorted by input order)
        // Intuition: For each position j, add (j * ri - sum of previous ri's) to get contribution
        long long sum_row = 0;
        long long left_sum = 0;  // Cumulative sum of rows up to j-1
        for (int j = 0; j < pos.size(); j++) {
            sum_row += (long long)j * pos[j].first - left_sum;
            left_sum += pos[j].first;
        }
        // Now sort by column to compute |ci - cj| sums
        sort(pos.begin(), pos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        long long sum_col = 0;
        left_sum = 0;  // Reset for columns
        for (int j = 0; j < pos.size(); j++) {
            sum_col += (long long)j * pos[j].second - left_sum;
            left_sum += pos[j].second;
        }
        // Add row and column contributions to total answer
        ans += sum_row + sum_col;
    }

    cout << ans << endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
