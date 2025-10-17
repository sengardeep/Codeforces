#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int a,b;
   cin>>a>>b;
   auto msb=[](int n){
    int x=0;
    while(n){
        n>>=1;
        x++;
    }
    return x;
   };
   if(msb(a) < msb(b)){
    cout<<-1<<endl;
    return;
   }
   int m=max(msb(a),msb(b));
   int num=0;
   for(int i=0;i<m;i++){
    if(((a>>i)&1)==0 && ((b>>i)&1)==1) num|=(1<<i);
   }
   vector<int> ans;
   if(num<=a) a^=num;
   if(num)
   ans.pb(num);
   num=0;
   for(int i=0;i<m;i++){
    if(((a>>i)&1)==1 && ((b>>i)&1)==0) num|=(1<<i);
   }
   if(num<=a) a^=num;
//    dbg(a);
   if(num)
   ans.pb(num);
   cout<<ans.size()<<endl;
   if(ans.empty()) return;
   for(auto it : ans) cout<<it<<" ";
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
