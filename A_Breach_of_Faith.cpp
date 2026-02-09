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
   cin>>n;
   vector<int> v(2*n);
   for(int i=0;i<2*n;i++) cin>>v[i];
   sort(all(v));
   int mx=v.back();
   cout<<mx<<" ";
   int first=0,second=0;
   for(int i=0;i<(2*n-1);i++){
    if(i<n-1) first+=v[i];
    else second+=v[i];
   }
   int el=mx-(first-second);
   cout<<el<<" ";
   int j=0,i=n-1;
   while(i<(2*n-1)) 
   {
       cout<<v[i++]<<" ";
       if(j<n-1)
       cout<<v[j++]<<" ";
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
