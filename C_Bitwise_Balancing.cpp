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
   int b,c,d;
   cin>>b>>c>>d;
   int a=0;
   for(int i=0;i<=61;i++){
    int x=(1LL<<i);
    bool f1=(b&x),f2=(c&x),f3=(d&x);
    if((!f1 && f2 && f3) || (f1 && !f2 && !f3)){
        cout<<-1<<endl;
        return;
    }
    if((!f1 && !f2 && f3)||(f1 && f2 && !f3)) a|=x;
   }
   cout<<a<<endl;
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
