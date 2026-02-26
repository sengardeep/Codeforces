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
   int h,w,x1,y1,x2,y2;
   cin>>h>>w>>x1>>y1>>x2>>y2;
   int diff=(x2-x1-1);
   if(diff<0) {
    cout<<"Draw"<<endl;
    return;
   }
   int flag=1;
   if(diff%2){
    //Bob might be the winner
    int p=(y1>y2)?1:-1;
    while(x2-x1 > 1){
        if(flag) {
            x1++;
            if(y1+p>0 && y1+p<=w)
            y1+=p;
        }else{
            x2--;
            if(y2+p>0 && y2+p<=w)
            y2+=p;
        }
        flag^=1;
    }
    if(y2-1 == y1 || y2==y1 || y2+1==y1) cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
   }else{
    //Alice might be the winner
    int p=(y1>y2)?-1:1;
    while(x2-x1 > 1){
        if(flag) {
            x1++;
            if(y1+p >0 && y1+p<=w)
            y1+=p;
        }else{
            x2--;
            if(y2+p >0 && y2+p<=w)
            y2+=p;
        }
        flag^=1;
    }
    if(y1-1==y2 || y1==y2 || y1+1==y2) cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;
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
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
