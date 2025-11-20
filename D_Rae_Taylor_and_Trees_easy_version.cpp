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
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> suff(n);
   suff[n-1]=v[n-1];
   for(int i=n-2;i>=0;i--) suff[i]=max(v[i],suff[i+1]);
   int curr=1e9;
   for(int i=0;i<n-1;i++){
    curr=min(curr,v[i]);
    if(curr>suff[i+1]){
        cout<<"No"<<endl;
        return;
    }
   }
   cout<<"Yes"<<endl;
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
