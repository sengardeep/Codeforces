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
   vector<int> v(m);
   for(int i=0;i<m;i++) cin>>v[i];
   bool flag=1;
   for(int i=0;i<m-1;i++){
    if(v[i]==v[i+1]-1) continue;
    else {
        flag=0;
        break;
    }
   }
   if(flag){
    int len = m + (v[0]-1);
    cout<<n-len+1<<endl;
    return;
   }
   else{
    cout<<1<<endl;
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
