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
   vector<char> dir{'L','R','U','D'};
   vector<pii> d{{0,-1},{0,1},{-1,0},{1,0}};
   queue<pii> q;
   int r=0,c=0;
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]=='B') { r=i; c=j; }
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]=='A') q.push({i,j});
   while(!q.empty()){
    int row=q.front().first,col=q.front().second;
    q.pop();
    if(row==r && col==c) break;
    for(int i=0;i<4;i++){
        int r=row+d[i].first,c=col+d[i].second;
        if(r<0||r>n-1||c<0||c>m-1) continue;
        if(v[r][c]=='#') continue;
        if(v[r][c]=='L' || v[r][c]=='R' || v[r][c]=='U' || v[r][c]=='D' || v[r][c]=='A') continue;
        v[r][c]=dir[i];
        q.push({r,c});
    }
   }
   if(v[r][c]=='B'){
    cout<<"NO";
    return;
   }
   cout<<"YES"<<endl;
   string ans="";
   while(v[r][c] != 'A'){
    char ch=v[r][c];
    ans+=ch;
    if(ch=='L') c+=1;
    if(ch=='R') c-=1;
    if(ch=='U') r+=1;
    if(ch=='D') r-=1;
   }
   cout<<ans.size()<<endl;
   reverse(ans.begin(),ans.end());
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
