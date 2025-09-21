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
   string s;
   cin>>s;
   string ans="";
   char l0='a',l1='a';
   for(auto c : s) {
    if(c >= l0){
        ans += '0';
        l0 = c;
    }
    else if(c >= l1){
        ans += '1';
        l1 = c;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
   }
   cout<<"YES"<<endl;
   cout<<ans;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
