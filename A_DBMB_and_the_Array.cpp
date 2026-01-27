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
   int n,s,x;
   cin>>n>>s>>x;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int sum=accumulate(all(v),0LL);
   int diff=s-sum;
   if(diff>=0 && diff%x==0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
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
