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
   int n;
   cin>>n;
   if(n==1) {
    cout<<1<<endl;
    return;
   }
   int setbit=0;
   for(int i=0;i<=31;i++){
    if(n&(1<<i)) setbit++;
   }
   if(setbit==1){
    cout<<-1<<endl;
    return;
   }
   vector<int> v(n);
   v[n-1]=1;
   for(int i=n-2;i>=1;i--){
    v[i]=1^(i+1);
   }
   if(n&1){
    v[0]=n-1;
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
    return;
   }
   int pos=0;
   for(int i=0;i<31;i++){
    if(n&(1<<i)){
        pos=i;
        break;
    }
   }
   int idx=(1<<pos)-1;
   v[0]=v[idx];
   v[idx]=n;
   for(auto x : v) cout<<x<<" ";
   cout<<endl;
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
