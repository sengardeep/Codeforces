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
   int m=1LL<<n;
   vector<int> v(m);
   for(int i=0;i<m;i++) cin>>v[i];
   vector<int> pre(m,0);
   pre[0]=v[0];
   for(int i=1;i<m;i++) pre[i]=pre[i-1]^v[i];
   auto rangeXor=[&](int l,int r){
    int ans=pre[r];
    return (l>0)?(ans^pre[l-1]):ans;
   };
   while (q--)
   {
    int idx,val;
    cin>>idx>>val;
    --idx;
    int x=v[idx],ans=0;
    for(int i=0;i<n;i++){
        int curr=(1LL<<i);
        int block=idx/curr;
        int l1=block*curr;
        int r1=l1+curr-1;
        int l2=0;
        if(block%2) l2=l1-curr;
        else l2=l1+curr;
        int r2=l2+curr-1;
        int p1=rangeXor(l1,r1),p2=rangeXor(l2,r2);
        p1^=x;
        p1^=val;
        if((p1>p2)||(p1==p2 && l1<l2)) continue;
        ans+=curr;
    }
    cout<<ans<<endl;
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
