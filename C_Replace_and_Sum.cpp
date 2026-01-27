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
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   for(int i=n-1;i>=0;i--) {
    a[i]=max(a[i],b[i]);
    if(i<n-1) a[i]=max(a[i],a[i+1]);
   }
   vector<int> pre(n,0);
   pre[0]=a[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
   auto query=[&](int l,int r){
    int ans=pre[r];
    return l>0?ans-pre[l-1]:ans;
   };
   while(q--){
    int l,r;
    cin>>l>>r;
    --l;--r;
    cout<<query(l,r)<<" ";
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
