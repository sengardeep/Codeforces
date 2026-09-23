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
   string s;
   cin>>s;
   if(s[0]=='1'){
    int ans=count(all(s),'0');
    cout<<ans<<endl;
    return;
   }
   int zero=0,one=0;
   for(int i=0;i<n;i++) {
    zero+=s[i]=='0';
   }
   int ans=zero;
   for(int i=0;i<n;i++){
    if(s[i]=='1') one++;
    else zero--;
    ans=min(ans,zero+one);
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
