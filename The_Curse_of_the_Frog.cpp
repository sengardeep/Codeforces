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
   int n,x;
   cin>>n>>x;
   vector<int> a(n),b(n),c(n);
   for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
   int temp=0;
   for(int i=0;i<n;i++) temp += (b[i]-1)*a[i];
   if(temp>=x) {
    cout<<0<<endl;
    return;
   }
   int mx=0;
   for(int i=0;i<n;i++){
    mx=max(mx,b[i]*a[i]-c[i]);
   }
   if(mx<=0){
    cout<<-1<<endl;
    return;
   }
   int diff=(x-temp);
   int ans=(diff+mx-1)/mx;
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
