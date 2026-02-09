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
   int n,m;
   cin>>n>>m;
   vector<int> a(n),b(m);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<m;i++) cin>>b[i];
   int x=a[0];
   sort(all(a));
   sort(all(b));
   vector<int> v(m);
   for(int i=0;i<m;i++){
    if(b[i]<=x) v[i]=1;
    else{
        auto lb=lower_bound(all(a),b[i])-begin(a);
        v[i]=(n-lb+1);
    }
   }
   sort(all(v));
   for(int i=0;i<m;i++){
    int ans=0;
    for(int j=i;j<m;j+=(i+1)) ans+=v[j];
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
