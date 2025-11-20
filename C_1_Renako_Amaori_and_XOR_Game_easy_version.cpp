#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   
   int xrA=0,xrB=0;
   for(auto it : a) xrA^=it;
   for(auto it : b) xrB^=it;

   if(xrA==xrB){
      cout<<"Tie"<<endl;
      return;
   }

   int diff=xrA^xrB;
   int msb=0;
    for(int i = 20; i >= 0; --i) {
        if((diff >> i) & 1) {
            msb = i;
            break;
        }
    }
   for(int i=n-1;i>=0;i--){
      int bitA=(a[i]>>msb)&1;
      int bitB=(b[i]>>msb)&1;
      if(bitA!=bitB){
         if(i%2){
            cout<<"Mai"<<endl;
            return;
         }else{
            cout<<"Ajisai"<<endl;
            return;
         }
      }
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
