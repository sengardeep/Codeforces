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
    string s;
    cin >> s;

    vector<int> l(m), r(m);
    for(int i = 0; i < m; i++) cin >> l[i];
    for(int i = 0; i < m; i++) cin >> r[i];

    int q;
    cin >> q;

    vector<int> diff(n + 1, 0);

    while(q--) {
        int x;
        cin >> x;
        x--;

        int idx = upper_bound(l.begin(), l.end(), x + 1) - l.begin() - 1;

        int li = l[idx] - 1;
        int ri = r[idx] - 1;

        int a = min(x, li + ri - x);
        int b = max(x, li + ri - x);

        diff[a]++;
        diff[b + 1]--;
    }

    for(int i = 1; i < n; i++)
        diff[i] += diff[i - 1];

    for(int seg = 0; seg < m; seg++) {
        int i = l[seg] - 1;
        int j = r[seg] - 1;
        while(i < j) {
            if(diff[i] % 2)
                swap(s[i], s[j]);
            i++; j--;
        }
    }

    cout << s << endl;
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
