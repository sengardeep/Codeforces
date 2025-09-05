#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

vector<vector<int>> segTree;
int n,q;
vector<vector<int>> v;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            segTree[vx][vy] = v[lx][ly];
        else
            segTree[vx][vy] = segTree[vx*2][vy] + segTree[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        segTree[vx][vy] = segTree[vx][vy*2] + segTree[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, n-1);
}
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return segTree[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}
int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, n-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}

void solve() {
    cin>>n>>q;
    v.resize(n,vector<int>(n,0));
    segTree.resize(4*n,vector<int>(4*n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++) if(s[j]=='*') v[i][j]=1;
    }
    build_x(1,0,n-1);
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<sum_x(1,0,n-1,r1-1,r2-1,c1-1,c2-1)<<endl;
    }
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
