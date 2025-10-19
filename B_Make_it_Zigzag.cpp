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
   vector<int> pre(n,0);
   pre[0]=v[0];
   for(int i=1;i<n;i++) pre[i]=max(pre[i-1],v[i]);
   int ans=0;
   for(int i=1;i<n;i++){
    if(i%2){
        //<>
        v[i]=pre[i];
        if(v[i-1]>=v[i]) {
            ans+=abs(v[i-1]-v[i])+1;
        }
    }
    else{
        //><
        v[i-1]=pre[i-1];
        if(v[i]>=v[i-1]){
            ans+=abs(v[i-1]-v[i])+1;
            v[i]=v[i-1]-1;
        }
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

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
