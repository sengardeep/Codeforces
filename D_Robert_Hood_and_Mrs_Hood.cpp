#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,d,k;
   cin>>n>>d>>k;
   vector<int> starts(k),ends(k);
   for(int i=0;i<k;i++) cin>>starts[i]>>ends[i];
   sort(begin(starts),end(starts));
   sort(begin(ends),end(ends));
   int maxi=0,idx1=0;
   int mini=n+1,idx2=0;
   int i=1,j=d;
   while(j<=n){
      int  S = upper_bound(starts.begin(), starts.end(), j) - starts.begin();
      int E = lower_bound(ends.begin(),ends.end(),i)-ends.begin();
      int res = S-E;
      if(res > maxi) {maxi=res;idx1=i;}
      if(res < mini) {mini=res;idx2=i;}
      i++;
      j++;
   }
   cout<<idx1<<" "<<idx2<<endl;
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
