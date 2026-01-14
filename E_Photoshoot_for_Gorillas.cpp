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
   int n,m,k;
   cin>>n>>m>>k;
   int w;
   cin>>w;
   vector<int> v(w);
   for(int i=0;i<w;i++) cin>>v[i];
   vector<vector<int>> diff(n+1,vector<int>(m+1,0));
   for(int i=0;i+k-1<n;i++){
    for(int j=0;j+k-1<m;j++){
        diff[i][j]+=1;
        diff[i+k][j]-=1;
        diff[i][j+k]-=1;
        diff[i+k][j+k]+=1;
    }
   } 
   priority_queue<int> pq;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i) diff[i][j]+=diff[i-1][j];
        if(j) diff[i][j]+=diff[i][j-1];
        if(i && j) diff[i][j]-=diff[i-1][j-1];
        pq.push(diff[i][j]);
    }
   }
   sort(all(v));
   reverse(all(v));
   int ans=0;
   for(int i=0;i<w;i++){
    int x=pq.top();
    pq.pop();
    ans+=v[i]*x;
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
