#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n,m;
   cin>>n>>m;
   int x=ask(1,1);
   int r1=1,c1=1;
   int step=x;
   if(c1+step<=m){
    c1+=step;
   }
   else {
    c1=m;
    step-=(m-1);
    r1+=step;
   }
   step=x;
   x = ask(r1,c1);
   int r2=1,c2=1;
   if(r2+step<=n){
    r2+=step;
   }
   else {
    r2=n;
    step-=(n-1);
    c2+=step;
   }
   int y=ask(r2,c2);
   int x1=r1,y1=c1,x2=r2,y2=c2;
   x1 += (x/2);
   y1 -= (x/2);
   x2 -= (y/2);
   y2 += (y/2);
   int q = ask(x1,y1);
   if(q==0) cout<<"! "<<x1<<" "<<y1<<endl;
   else cout<<"! "<<x2<<" "<<y2<<endl;
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
