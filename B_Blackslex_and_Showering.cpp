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
   int sum=0;
   for(int i=1;i<n;i++) sum+=abs(v[i]-v[i-1]);
   int ans=sum;
   for(int i=0;i<n;i++){
    int temp=sum;
    if(i==0){
        temp-=abs(v[i]-v[i+1]);
        ans=min(ans,temp);
    }else if(i==n-1){
        temp-=abs(v[i]-v[i-1]);
        ans=min(ans,temp);
    }else{
        temp-=abs(v[i]-v[i+1]);
        temp-=abs(v[i]-v[i-1]);
        temp+=abs(v[i-1]-v[i+1]);
        ans=min(ans,temp);
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
