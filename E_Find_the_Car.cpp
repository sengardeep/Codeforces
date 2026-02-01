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
   int n,k,q;
   cin>>n>>k>>q;
   vector<int> a(k),b(k);
   for(int i=0;i<k;i++) cin>>a[i];
   for(int i=0;i<k;i++) cin>>b[i];
   while(q--){
    int d;
    cin>>d;
    int ub=upper_bound(all(a),d)-begin(a);
    if(ub==k){
        cout<<b[ub-1]<<" ";
        continue;
    }
    int ans=0;
    if(ub>0) 
    {
        ans+=(b[ub-1]);
        d-=a[ub-1];
    }
    int dist = a[ub] - (ub > 0 ? a[ub-1] : 0);
    int time = b[ub] - (ub > 0 ? b[ub-1] : 0);
    int rem = (d * time) / dist;
    ans += rem;
    cout<<ans<<" ";
   }
   cout<<endl;
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
