#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    
    vector<pair<int, int>> pos(n * m + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            pos[b[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        int targetRow = pos[a[i][0]].first;
        for (int j = 1; j < m; j++) {
            if (pos[a[i][j]].first != targetRow) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int targetCol = pos[a[0][j]].second;
        for (int i = 1; i < n; i++) {
            if (pos[a[i][j]].second != targetCol) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
