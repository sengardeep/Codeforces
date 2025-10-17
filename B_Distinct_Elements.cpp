#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans(n, 0);
    vector<int> pos(n, 0);
    int prev = 0, nxt = 1;
    for (int i = 0; i < n; i++) {
        int diff = v[i] - prev;
        prev = v[i];
        if (diff == i + 1) {
            ans[i] = nxt;
            pos[i] = nxt;
            nxt++;
        } else {
            int p = i - diff;
            int val = pos[p];
            ans[i] = val;
            pos[p] = 0;
            pos[i] = val;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
