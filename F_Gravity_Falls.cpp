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
    vector<vector<int>> v(n);
    vector<int> sizes;
    int maxSize=0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        sizes.pb(k);
        maxSize=max(maxSize,k);
        v[i].resize(k);
        for (int j = 0; j < k; j++) cin >> v[i][j];
    }
    const int maxi = LLONG_MAX;
    for(int i=0;i<n;i++){
        int rem = maxSize-sizes[i];
        while(rem--){
            v[i].pb(maxi);
        }
    }
    sort(begin(v), end(v));
    vector<int> ans;
    int idx=0;
    for(int i=0;i<n;i++){
        for(size_t j=idx; j<v[i].size() && v[i][j] != maxi; j++){
            ans.pb(v[i][j]);
            idx++;
        }
    }
    for(auto it : ans) cout<<it<<" ";
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
