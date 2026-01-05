#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   string src,des;
   cin>>src>>des;
   int r1=(src[0]-'a'),c1=(src[1]-'1');
   int r2=(des[0]-'a'),c2=(des[1]-'1');
   queue<pii> q;
   vector<vector<int>> dp(8,vector<int>(8,INT_MAX));
   q.push({r1,c1});
   dp[r1][c1]=0;
   pii dir[8]={{1,2},{2,1},{-1,2},{1,-2},{-2,1},{2,-1},{-2,-1},{-1,-2}};
   while(!q.empty()){
      auto [r,c] = q.front();
      q.pop();
      for(int i=0;i<8;i++){
         int row=r+dir[i].first,col=c+dir[i].second;
         if(row<0||row>=8||col<0||col>=8) continue;
         if(dp[row][col] != INT_MAX) continue;
         dp[row][col]=min(dp[row][col],dp[r][c]+1);
         q.push({row,col});
      }
   }
   cout<<dp[r2][c2]<<endl;
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
