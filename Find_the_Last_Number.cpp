#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   auto ask=[](int i,int x){
    cout<<"? "<<i<<" "<<x<<endl;
    int ans; cin>>ans;
    return ans;
   };
   int num = 0;   
   for(int i = 1; i <= 62; i++){
       int val = (1LL << i);
       if(val > n){
           num = val;
           break;
        }
   }
   set<int> set;
   for(int i=1;i<=n-1;i++){
    int x=ask(i,num);
    set.insert(x);
   }
   for(int i=1;i<=n;i++){
    if(set.count(i)) continue;
    else {
        cout<<"! "<<i<<endl;
        return;
    }
   }

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
