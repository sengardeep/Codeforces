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
    int n,m,l;
    cin>>n>>m>>l; 
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;

    multiset<int> s;
    for (int i = 0; i < min(m, n + 1); i++) s.insert(0);

    int mx = n + 1;
    for (int i = 1; i <= n; i++) {
        mx--;
        for (int j = a[i - 1]; j < a[i]; j++) {
            s.insert((*s.begin()) + 1);
            s.erase(s.begin());
        }

        s.erase(prev(s.end()));

        if ((int)s.size() < min(m, mx)) s.insert(0);
    }

    int ans = (*prev(s.end())) + l - a[n];
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
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
