#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int x,y;
   cin>>x>>y;
   if(x==y){
    cout<<-1<<endl;
    return;
   }
   if(x<y){
    if(x==0) cout<<1<<endl;
    else cout<<2<<endl;
    return;
   }
   int a=0,b=0;
   a+=1;
   if(y>1) b=y;
   else{
    cout<<-1<<endl;
    return;
   }
   if(x-a > y) {
    cout<<3<<endl;
   } 
   else cout<<-1<<endl;
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
