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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   for(int i=0;i<n;i++) v[i]=(v[i]%k);
   map<int,int> map;
   for(int i=0;i<n;i++) 
   {
       if(v[i])
       map[k-v[i]]++;
   }
   int ans=0;
   for(auto [x,f] : map){
    if(x==0) continue;
    else{
        int temp=x;
        temp+=(f-1)*k;
        ans=max(ans,temp+1);
    }
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
