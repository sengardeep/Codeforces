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
   vector<int> v(n),c(n);
   for(int i=0;i<n;i++) cin>>v[i];
   for(int i=0;i<n;i++) cin>>c[i];
   int ans=0;
   for(int i=0;i<n-1;i++){
    if(v[i]>v[i+1]){
        if(c[i]>c[i+1]){
            v[i+1]=v[i];
            ans+=c[i+1];
        }else{
            if(i>0 && v[i-1]<=v[i+1])
            {
                v[i]=v[i-1];
                ans+=c[i];
            }
            else {
                v[i+1]=v[i];
                ans+=c[i+1];
            }
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
