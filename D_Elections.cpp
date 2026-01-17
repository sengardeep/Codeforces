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
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   v[0]+=k;
   int mx1=-1,prevSum=0;
   vector<int> suff(n,0);
   suff[n-1]=v[n-1];
   for(int i=n-2;i>=0;i--) suff[i]=max(suff[i+1],v[i]);
   for(int i=0;i<n;i++){
    int ans=0;
    int curr=v[i];
    int mx2=((i<n-1)?suff[i+1]:-1);
    if(mx1>=curr) {
        ans+=i;
        curr+=prevSum;
        if(mx2>curr){
            ans++;
        }
    }else if(mx2>curr){
        curr+=prevSum;
        if(curr>=mx2){
            ans+=i;
        }else{
            ans+=(i+1);
        }
    }
    prevSum+=v[i];
    mx1=max(mx1,v[i]);
    cout<<ans<<" ";
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
