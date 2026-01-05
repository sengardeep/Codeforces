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
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   vector<int> pre(n);
   pre[0]=b[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+b[i];
   int prev=0;
   vector<int> cont(n+1,0),ans(n+1,0);
   for(int i=0;i<n;i++){
    int num=a[i]+prev;
    int ub=upper_bound(all(pre),num)-begin(pre);
    prev+=b[i];
    if(ub==i){
        // dbg(ub);
        ans[ub]+=a[ub];
        continue;
    }
    ub--;
    cont[i]+=1;
    cont[ub+1]-=1;
    ans[ub+1]+=(a[i]-pre[ub]+(i>0?pre[i-1]:0));
   }
   for(int i=1;i<=n;i++) cont[i]+=cont[i-1];
   for(int i=0;i<n;i++) {
    ans[i]+=(cont[i]*b[i]);
    cout<<ans[i]<<" ";
   }
   cout<<endl;
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
