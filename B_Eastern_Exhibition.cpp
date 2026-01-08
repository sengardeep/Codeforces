#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(x) begin(x),end(x)

void solve() {
   int n;
   cin>>n;
   vector<int> x(n),y(n);
   for(int i=0;i<n;i++) cin>>x[i]>>y[i];
   sort(all(x));
   sort(all(y));
   if(n%2){
    cout<<1<<endl;
    return;
   }else{
    int a=(x[n/2]-x[(n/2)-1]+1);
    int b=(y[n/2]-y[(n/2)-1]+1);
    cout<<a*b<<endl;
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
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
