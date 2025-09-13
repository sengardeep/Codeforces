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
   bool flag=false;
   vector<int> odd;
   int evenSum=0;
   for(int i=0;i<n;i++) 
   {
       cin>>v[i];
       if(v[i]&1) {
        odd.pb(v[i]);
       }
       else evenSum+=v[i];
   }
   if(odd.empty()){
    cout<<0<<endl;
    return;
   }
   sort(odd.begin(),odd.end());
   int i=0,j=odd.size()-1;
   int ans=0;
   while(i<=j){
    ans+=odd[j];
    j--;
    i++;
   }
   cout<<ans+evenSum<<endl;
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
