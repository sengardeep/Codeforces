#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

vector<int> seq;

void solve() {
   int n;
   cin>>n;
   vector<int> vis(n+1,0);
   queue<pii> q;
   auto ub=lower_bound(all(seq),n)-begin(seq);
   int prev=seq[ub-1];
   int x=n-prev;
   int ans = 0;
   for (int r = ub; r >= 1; r--) {
       int start_col = max(1LL, x - (ub - r));
       int end_col = min(r, x);
       for (int c = start_col; c <= end_col; c++) {
           int num = seq[r-1] + c;
           ans += (num * num);
       }
   }
   cout<<ans<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   int i=1;
   seq.pb(0);
   while(seq.back()<=1e6){
    seq.pb(seq.back()+i);
    i++;
   }
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
