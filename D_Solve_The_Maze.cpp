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
   auto check=[&](int i,int j){
    if(i<0||j<0||i>n-1||j>m-1) return false;
    return true;
   };
   vector<pii> dir{{-1,0},{0,-1},{1,0},{0,1}};
   bool flag=false;
   auto make_boundaries=[&](int i,int j){
    for(int k=0;k<4;k++){
        int r=i+dir[k].first,c=j+dir[k].second;
        if(check(r,c)) {
            if(v[r][c]=='B') continue;
            if(v[r][c]=='G') 
            {
                flag=true;
                return;
            }
            v[r][c]='#';
        }
    }
   };
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]=='B') 
        {
            make_boundaries(i,j);
            if(flag){
                cout<<"No"<<endl;
                return;
            }
        }
    }
   }
   function<void(int,int)> dfs=[&](int r,int c)->void{
    if(check(r,c)==false) return;
    if(v[r][c]=='#') return;
    if(v[r][c]=='B') {
        flag=true;
        return;
    }
    // dbg(r);
    // dbg(c);
    v[r][c]='#';
    for(int i=0;i<4;i++){
        int row=r+dir[i].first,col=c+dir[i].second;
        // dbg(row);
        // dbg(col);
        dfs(row,col);
    }
   };
   dfs(n-1,m-1);
   if(flag){
    cout<<"No"<<endl;
    return;
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]=='G')
        {
            // dbg(i);
            // dbg(j);
            cout<<"No"<<endl;
            return;
        }
    }
   }
   cout<<"Yes"<<endl;
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
