#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    int n,m,j;
    cin>>n>>m>>j;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pii> d={{-1,0},{0,-1},{1,0},{0,1}};
    auto bfs=[&](int r,int c)->int{
        int ans=0;
        queue<pii> q;
        q.push({r,c});
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(v[r][c]=='x') return ans;
            if(vis[r][c]) continue;
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                int row=r+d[i].first,col=c+d[i].second;
                if(row<0 || col<0 || row>=n || col>=m) continue;
                if(v[row][col]=='#' || vis[row][col]==1) continue;
                if(v[row][col]=='s') ans++;
                q.push({row,col}); 
            }
        }
        return 1e9;
    };
    int mn=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='@') mn=min(mn,bfs(i,j)); 
        }
    }
    if(2*mn <= j) cout<<"SUCCESS";
    else cout<<"IMPOSSIBLE";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}