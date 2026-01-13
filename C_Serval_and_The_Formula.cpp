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
   int a,b;
   cin>>a>>b;
   if(a==b){
    cout<<-1<<endl;
    return;
   }
   int ans=0;
   for(int i=0;i<60;i++){
    if(!(a&(1LL<<i)) && !(b&(1LL<<i))){ continue;}
    if((a+b)==(a^b)) break;
    ans+=(1LL<<(i));
    a+=(1LL<<(i));
    b+=(1LL<<(i));
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
