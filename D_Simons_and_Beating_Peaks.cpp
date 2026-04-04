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
   vector<int> idx(n+1);
   for(int i=0;i<n;i++) idx[v[i]]=i;
   //Sparse Table
   auto findLog=[](int n){
      int ans=0;
      while(1<<(ans+1)<=n) ans++;
      return ans;
   };
   int LOG=findLog(n);
   vector<vector<int>> st(n,vector<int>(LOG+1));
   for(int i=0;i<n;i++) st[i][0]=v[i];
   for(int j=1;j<=LOG;j++) for(int i=0;i+(1<<j)-1<n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
   auto query=[&](int l,int r){
      int len=r-l+1;
      int k=findLog(len);
      return max(st[l][k],st[r-(1<<k)+1][k]);
   };
   function<int(int,int)> helper=[&](int l,int r)->int{
      if(l>=r) return 0;
      int mx = query(l,r);
      int index = idx[mx];

      int left = index-l + helper(index+1,r);
      int right = r-index + helper(l,index-1);
      
      return min(left,right); 
   };
   cout<<helper(0,n-1)<<endl;
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
