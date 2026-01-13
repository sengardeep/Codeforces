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
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> diff[n];
   for(int i=1;i<n;i++) diff[abs(v[i]-v[i-1])].pb(i);
   auto calc=[&](int x){
    return (x*(x+1))/2;
   };
   vector<int> vis(n,0),left(n,-1),right(n,-1);
   vector<int> ans(n);
   int temp=0;
   for(int i=n-1;i>=1;i--){
    for(auto x : diff[i]){
        vis[x]=1;
        int lo=x,hi=x;
        if(x>0 && vis[x-1]){
            int length=(x-1)-left[x-1]+1;
            temp -= calc(length);
            lo=left[x-1];
        }
        if(x<n-1 && vis[x+1]){
            int length=right[x+1]-(x+1)+1;
            temp -= calc(length);
            hi=right[x+1];
        }

        right[lo]=hi;
        left[hi]=lo;
        temp+=calc(hi-lo+1);
    }
    ans[i]=temp;
   }
   for(int i=1;i<n;i++) cout<<ans[i]<<" ";
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
