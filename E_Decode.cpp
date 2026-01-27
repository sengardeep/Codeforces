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
   int n=s.size();
   map<int,int> map;
   int ans=0;
   int sum=0;
   map[0]=1;
   for(int i=0;i<n;i++){
    char c=s[i];
    sum+=(c=='0');
    sum-=(c=='1');
    if(map.count(sum)){
        ans=(ans+(map[sum]*(n-i))%mod)%mod;
    }
    map[sum]=(map[sum]+(i+2))%mod;
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
