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
   map<int,int> map;
   for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    map[x]++;
   }
   int req=0,rem=map[k];
   for(int i=0;i<k;i++) if(map.count(i) == 0) req++;
   int ans=0;
   if(rem >= req) {
    cout<<rem<<endl;
    return;
   }
   else
   {
    cout<<rem + (req-rem) << endl;
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
