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
   string s;
   cin>>s;
   int flag=1;
   for(int i=1;i<n;i++){
    if(s[i]<s[i-1]) {
        flag=0;
        break;
    }
   }
   if(flag){
    cout<<"Bob"<<endl;
    return;
   }
   cout<<"Alice"<<endl;
   int zero=count(all(s),'0');
   vector<int> ans;
   for(int i=0;i<n;i++){
    if(i<zero && s[i]=='1') ans.pb(i+1);
    if(i>=zero && s[i]=='0') ans.pb(i+1);
   }
   cout<<ans.size()<<endl;
   for(auto x : ans) cout<<x<<" ";
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
