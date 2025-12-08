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
   set<int> s;
   set<int> vis;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    s.insert(x);
    vis.insert(x);
   }
   vector<int> ans;
   while(!s.empty()){
    int x=*s.begin();
    ans.pb(x);
    int start=x;
    while(start<=k){
        if(vis.count(start)){
            if(s.count(start))
            s.erase(s.find(start));
        }else {
            cout<<-1<<endl;
            return;
        }
        start+=x;
    }
   }
   cout<<ans.size()<<endl;
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
