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
   string s;
   cin>>s;
   int x = 9-(s[0]-'0');
   int n=s.size();
   vector<int> rem;
   for(int i=1;i<n;i++) rem.pb(s[i]-'0');
   sort(all(rem));
   int ans1=n-1;
   for(int i=0;i<rem.size();i++) {
    if(rem[i]<=x){
        x-=rem[i];
        ans1--;
    }
   }
   int ans2=n;
   x=8;
   for(int i=0;i<rem.size();i++) {
    if(rem[i]<=x){
        x-=rem[i];
        ans2--;
    }
   }
   cout<<min(ans1,ans2)<<endl;
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
