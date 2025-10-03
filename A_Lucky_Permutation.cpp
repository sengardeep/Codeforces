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

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (!((n % 4 == 0) || (n % 4 == 1))) {
        cout << -1 << endl;
        return;
    }

    vector<int> p(n + 1, 0);

    if (n % 4 == 1) {
        int mid = (n + 1) / 2;
        p[mid] = mid;
        for (int i = 1; i <= n / 2; i += 2) {
            int a = i, b = i + 1, c = n - i, d = n - i + 1;
            p[a] = c; p[c] = d; p[d] = b; p[b] = a;
        }
    } else { // n % 4 == 0
        for (int i = 1; i <= n / 2; i += 2) {
            int a = i, b = i + 1, c = n - i, d = n - i + 1;
            p[a] = c; p[c] = d; p[d] = b; p[b] = a;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? '\n' : ' ');
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
