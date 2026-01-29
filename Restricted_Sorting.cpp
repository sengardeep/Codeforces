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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   bool flag=1;
   for(int i=0;i+1<n;i++) 
   {
       if(v[i]>v[i+1])
       {
        flag=0;
        break;
       }
   }
   if(flag) {
    cout<<-1<<endl;
    return;
   }
   vector<int> sorted=v;
   sort(all(sorted));
   int mn=*min_element(all(v)),mx=*max_element(all(v));
   int ans=1e9;
   for(int i=0;i<n;i++){
    if(v[i]!=sorted[i]){
        int mini=abs(v[i]-mn),maxi=abs(v[i]-mx);
        ans=min(ans,max(mini,maxi));
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
