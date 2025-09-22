#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int l,r;
   cin>>l>>r;
   vector<int> ans(r+1),pos(r+1);
   iota(begin(ans),end(ans),0);
   iota(begin(pos),end(pos),0);
   //Pair each element with its compliment
   auto f = [&](int n){
      if(n == 0) return 0LL;
      int lg = 63 - __builtin_clzll((unsigned long long)n);
      return 1LL << lg;
   };
   vector<bool> done(r+1,false);
   for(int x = f(r); x > 0; x >>= 1){
      if(done[pos[x]]) continue;
      for(int i=pos[x],j=pos[x]-1;i<=r&&j>=0;i++,j--){
         if(done[i]) break;
         swap(pos[ans[i]],pos[ans[j]]);
         swap(ans[i],ans[j]);
         done[i]=done[j]=true;
      }
   }
   cout<<r*(r+1)<<endl;
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
