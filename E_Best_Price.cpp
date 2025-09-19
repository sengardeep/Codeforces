#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,k;
   cin>>n>>k;
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   sort(begin(a),end(a));
   sort(begin(b),end(b));
   vector<int> c=a;
   c.insert(end(c),begin(b),end(b));
   sort(begin(c),end(c));
   int ans=0;
   for(auto it : c){
    int neg = lower_bound(begin(a),end(a),it)-begin(a);
    int buy = lower_bound(begin(b),end(b),it)-begin(b);
    if(neg-buy > k) continue;
    ans=max(ans,it*(n-buy));
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

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
