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
   int n,k,d;
   cin>>n>>k>>d;
   vector<int> a(n),v(k);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<k;i++) cin>>v[i];

   int i=0,ans=0;
   for(int j=0;j<n;j++) ans+=(a[j]==(j+1));
   ans+=((d-1)/2);
   int m=d;
   while(i<2*n && i<m){
    int idx=i%k;
    int res=0,temp=0;
    d--;
    for(int j=0;j<v[idx]&&j<n;j++) a[j]++;
    for(int j=0;j<n;j++) temp+=(a[j]==(j+1));
    i++;
    if(d>0)
    {
        res+=temp;
        res+=((d-1)/2);
        ans=max(ans,res);
    }
    else break;
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
