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
   char c;
   cin>>c;
   string s;
   cin>>s;
   int i=0,j=n-1;
   int ans=0;
   while(i<j){
    if(s[i]==s[j]){
        i++;
        j--;
        continue;
    }
    ans+=2;
    if(s[i]==c || s[j]==c) ans--;
    i++;
    j--;
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
