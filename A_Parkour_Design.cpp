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
   int a,b;
   cin>>a>>b;
   if(b>0){
    //x+2,y+1
    if(b*2 > a) {
        cout<<"NO"<<endl;
        return;
    }
    a-=(b*2);
    if(a%3){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
   }else if(b<0){
    //x+4,y-1
    if(b*(-4) > a){
        cout<<"NO"<<endl;
        return;
    }
    a+=b*4;
    if(a%3){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
   }else{
    if(a%3){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
