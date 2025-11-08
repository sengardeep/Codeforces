#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,m;
   cin>>n>>m;
   multiset<int> ms;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    ms.insert(x);
   }
   vector<pii> b(m);
   for(int i=0;i<m;i++) cin>>b[i].first;
   for(int i=0;i<m;i++) cin>>b[i].second;
   vector<int> zeros;
   for(int i=0;i<m;i++) if(b[i].second==0) zeros.pb(b[i].first);
   int ans=0;
   sort(begin(b),end(b));
   for(int i=0;i<m;i++){
    if(!b[i].second) continue;
    auto lb=ms.lower_bound(b[i].first);
    if(lb==ms.end()) continue;
    ans++;
    ms.insert(max(*lb,b[i].second));
    ms.erase(lb);
   }
   sort(begin(zeros),end(zeros));
   for(auto it : zeros){
    auto lb=ms.lower_bound(it);
    if(lb==ms.end()) break;
    ans++;
    ms.erase(lb);
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
