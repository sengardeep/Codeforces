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
   int n,x,y;
   cin>>n>>x>>y;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> pre(n);
   for(int i=0;i<n;i++) pre[i]=v[i]/x;
   for(int i=1;i<n;i++) pre[i]+=pre[i-1];
   auto query = [&](int l,int r)->int{
    if(l>r) return 0;
    int ans=pre[r];
    return (l>0)?(ans-pre[l-1]):ans;
   };
   int ans=0;
   for(int i=0;i<n;i++){
    int curr=v[i];
    int left=query(0,i-1)*y;
    int right=query(i+1,n-1)*y;
    ans=max(ans,curr+left+right);
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
