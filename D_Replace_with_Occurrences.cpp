#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    vector<int> a(n, 0);
    int label = 0;

    for (auto &it : pos) {
        int k = it.first;
        auto &idx = it.second;
        if (idx.size() % k != 0) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < idx.size(); i += k) {
            ++label;
            for (int j = 0; j < k; ++j) {
                a[idx[i + j]] = label;
            }
        }
    }

    for(auto it : a) cout<<it<<" ";
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
