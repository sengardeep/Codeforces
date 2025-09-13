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
   int l=k,r=k+n-1;
   int start=l,end=r;
   int ans=1e10;
   auto segSum=[&](int l,int r)->int{
    int sumL=(l*(l-1))/2;
    int sumR=(r*(r+1))/2;
    return sumR-sumL;
   };
   while(start<=end){
    int mid = (start+end)/2;
    int fSum=segSum(l,mid),sSum=segSum(mid+1,r);
    int diff = fSum-sSum;
    if(diff==0){
        ans=0;
        break;
    }
    else if(diff<0){
        ans=min(ans,abs(diff));
        start=mid+1;
    }
    else{
        ans=min(ans,diff);
        end=mid-1;
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
