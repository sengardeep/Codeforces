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
   int x;
   cin>>x;
   auto digsum=[&](int x){
    string s=to_string(x);
    int ans=0;
    for(auto i : s) ans += (i-'0');
    return ans;
   };
   for(int i=0;i<=100;i++){
    int y=x+i;
    if(y-digsum(y)==x){
        cout<<10<<endl;
        return;
    }
   }
   cout<<0<<endl;
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
