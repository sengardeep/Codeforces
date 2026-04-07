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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') pos.push_back(i);
    }

    if (pos.empty()) {
        cout << 0 << " " << 0 << endl;
        return;
    }

    int mn = 0, mx = 0;
    int st = pos[0], prv = pos[0];

    for (int i = 1; i < (int)pos.size(); i++) {
        if (pos[i] - prv > 2) {
            int len = prv - st + 1;
            mn += (len + 2) / 2;
            mx += len;
            st = pos[i];
        }
        prv = pos[i];
    }

    int len = prv - st + 1;
    mn += (len + 2) / 2;
    mx += len;

    cout << mn << " " << mx << endl;
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
