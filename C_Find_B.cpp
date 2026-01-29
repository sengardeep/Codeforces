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
   int n,q;
   cin>>n>>q;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> pre(n,0),cnt(n,0);
   cnt[0]=(v[0]==1?1:0);
   pre[0]=v[0];
   for(int i=1;i<n;i++) {
    pre[i]=pre[i-1]+v[i];
    cnt[i]=cnt[i-1]+(v[i]==1?1:0);
   }
   while(q--){
    int l,r;
    cin>>l>>r;
    --l;
    --r;
    int sum=pre[r];
    if(l>0) sum-=pre[l-1];
    int one=cnt[r];
    if(l>0) one-=cnt[l-1];
    int len=r-l+1;
    // dbg(len);
    // dbg(sum);
    // dbg(one);
    if(one+len>sum || len==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
   }
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
