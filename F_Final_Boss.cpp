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
   int h,n;
   cin>>h>>n;
   vector<int> v(n),c(n);
   for(int i=0;i<n;i++) cin>>v[i];
   for(int i=0;i<n;i++) cin>>c[i];
   auto check=[&](int k){
    int x=0;
    for(int i=0;i<n;i++){
        int d=(k-1)/c[i];
        if(x>=h) return true;
        x += (v[i]*(d+1));
    }
    return (x>=h);
   };
   int start=1,end=1e13,ans=1e9;
   while(start<=end){
    int mid=start+(end-start)/2;
    if(check(mid)) {
        ans=mid;
        end=mid-1;
    }else start=mid+1;
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
