#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(x) begin(x),end(x)

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   sort(all(v));
   int i=0,j=n-1,x=0,ans=0;
   while(i<j){
    x+=v[i];
    if(x>=v[j]) 
    {
        ans+=v[j]+1;
        x-=v[j];
        j--;
    }
    i++;
   }
   if(i==j)
   {
    if(x==0 && v[i]==1) ans+=1;
    else
    ans+=(v[j]+x+3)/2;
    x=0;
   }
   if(x) 
   {
    if(x==1) ans++;
    else ans+=(x+3)/2;
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
