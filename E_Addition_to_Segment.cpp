#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
    int n, m;
    cin >> n >> m;

    struct BIT {
        int N;
        vector<long long> f;
        BIT(int n = 0) { init(n); }
        void init(int n) { N = n; f.assign(N + 1, 0); }
        void add(int i, long long v) {
            for (; i <= N; i += i & -i) f[i] += v;
        }
        long long sum(int i) {
            long long s = 0;
            for (; i > 0; i -= i & -i) s += f[i];
            return s;
        }
    } bit(n + 2);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            // add v to [l, r-1]
            bit.add(l + 1, v);
            bit.add(r + 1, -v);
        } else {
            int i;
            cin >> i;
            cout << bit.sum(i + 1) << endl;
        }
    }
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
