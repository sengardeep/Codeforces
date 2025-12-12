#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> odds,evens;
   for(auto it : v) 
   {
    if(it%2) odds.pb(it);
    else evens.pb(it);
   }
   int e=evens.size();
   sort(begin(odds),end(odds));
   reverse(begin(odds),end(odds));
   sort(begin(evens),end(evens));
   reverse(begin(evens),end(evens));
   if(odds.empty()){
       for(int j=0;j<n;j++){
           cout<<0<<" ";
       }
       cout<<endl;
       return;
   }

   vector<int> pre(evens.size()+1);
   for(int i=1;i<=evens.size();i++) pre[i]=pre[i-1]+evens[i-1];

   int mx=odds[0];
   vector<int> ans;
   for(int i=0;i<n;i++){
    int l=max(1LL,i+1-(int)evens.size());
    int r=min(i+1,(int)odds.size());
    int x=l;
    if(l%2==0) x++;
    if(x<=r) ans.pb(mx+pre[i+1-x]);
    else ans.pb(0);
   }
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
