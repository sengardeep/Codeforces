#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,m;
   cin>>n>>m;
   vector<string> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<pii> dir{{1,0},{0,1},{-1,0},{0,-1}};
   function<void(int,int)> dfs=[&](int row,int col){
    if(row<0 || row>n-1 || col<0 || col>m-1) return;
    if(v[row][col]=='#') return;
    v[row][col]='#';
    for(int i=0;i<4;i++){
        int r=row+dir[i].first,c=col+dir[i].second;
        dfs(r,c);
    }
   };
   int ans=0;
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]=='.') {ans++;dfs(i,j);}
   cout<<ans;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
