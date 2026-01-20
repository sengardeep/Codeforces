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
   int r;
   cin>>r;
   int mn=r*r,mx=((r+1)*(r+1))-1;
   auto lower=[&](int target,int start){
      int end=r;
      int ans=1e9;
      while(start<=end){
         int mid=(start+end)/2;
         if(mid*mid >= target){
            ans=mid;
            end=mid-1;
         }
         else start=mid+1;
      }
      return ans;
   };
   auto higher=[&](int target,int start){
      int end=r;
      int ans=-1;
      while(start<=end){
         int mid=(start+end)/2;
         if(mid*mid <= target){
            ans=mid;
            start=mid+1;
         }else end=mid-1;
      }
      return ans;
   };
   int type1=0,type2=0;
   for(int i=0;i<=r;i++){
      int lo=mn-(i*i);
      int hi=mx-(i*i);
      int l=lower(lo,i);
      int r=higher(hi,i);
      if(l>r) continue;
      int total=(r-l+1);
      int cnt=0;
      if(0>=l && 0<=r) cnt++;
      if(i>=l && i<=r) cnt++;
      type2+=cnt;
      type1+=(total-cnt);
   }
   cout<<(8*type1 + 4*type2 - 4)<<endl;
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
