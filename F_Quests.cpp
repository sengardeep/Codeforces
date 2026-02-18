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
   int n,c,d;
   cin>>n>>c>>d;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int mx=*max_element(all(v));
   if(mx*d < c){
    cout<<"Impossible"<<endl;
    return;
   }
   sort(all(v));
   reverse(all(v));
   vector<int> pre(n,0);
   pre[0]=v[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
   if(pre[min(d-1,n-1)]>=c){
    cout<<"Infinity"<<endl;
    return;
   }
   auto check=[&](int k){
    int sum=pre[min(k-1,n-1)];
    int div=d/k;
    int rem=d%k;
    int tot=sum*div;
    if(rem>0) tot+=pre[min(rem-1,n-1)];
    return tot>=c;
   };
   int start=1,end=d,ans=0;
   while(start<=end){
    int mid=(start+end)/2;
    if(check(mid)){
        ans=mid;
        start=mid+1;
    }else end=mid-1;
   }
   cout<<ans-1<<endl;
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
