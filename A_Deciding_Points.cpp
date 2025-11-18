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
   if(m>n){
    cout<<"NO"<<endl;
    return;
   }
   if(n%2==0 && (n+2)/2 >= m){
        cout<<"YES"<<endl;
        return;
    }
    if((2*m)-n > 2) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   int t=1;
   cin>>t;
   int i=1;
   while(t--){
    cout<<"Case #"<<i++<<": ";
    solve();
   }

   return 0;
}
