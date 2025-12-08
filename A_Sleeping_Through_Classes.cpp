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
   string s;
   cin>>s;
   int ans=0;
   for(int i=0;i<n;i++) {
    if(s[i]=='0') ans++;
    else {
        bool flag=true;
        for(int j=1;j<=k && i+j<n;j++){
            if(s[i+j]=='1') {
                flag=false;
                i=i+j-1;
                break;
            }
        }
        if(flag) i+=k;
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
