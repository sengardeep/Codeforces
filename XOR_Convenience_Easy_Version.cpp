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
   vector<int> v(n);
   set<int> set;
   v[n-1]=1;
   set.insert(1);
   for(int i=n-2;i>=1;i--) {
    v[i]=1^(i+1);
    set.insert(v[i]);
   }
   for(int i=1;i<=n;i++){
    if(!set.count(i)){
        v[0]=i;
        break;
    }
   }
   for(auto x : v) cout<<x<<" ";
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
